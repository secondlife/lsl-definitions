"""
Ruleset-to-Luau codegen. Supports any named ruleset declared under
builder-rulesets in lsl_definitions.yaml. The fluent SPP builder for
`prim-params` is the reference implementation.
"""

from __future__ import annotations

import dataclasses
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from lsl_definitions.lsl import LSLDefinitions


@dataclasses.dataclass(frozen=True)
class BuilderParamType:
    """Abstract user-facing input type, maps to a Luau type definition"""

    name: str
    luau_type: str


_RULESET_TYPES: dict[str, BuilderParamType] = {
    t.name: t
    for t in [
        BuilderParamType("integer", "number"),
        BuilderParamType("link", "number"),
        BuilderParamType("float", "number"),
        BuilderParamType("string", "string"),
        BuilderParamType("vector", "vector"),
        BuilderParamType("rotation", "quaternion"),
        BuilderParamType("boolean", "boolean"),
        BuilderParamType("asset", "(string | uuid)"),
    ]
}

# Maps value-type annotation string → FluentParamDescriptor semantic char.
# Consumed by any code that builds a C array of FluentParamDescriptor from
# a MemberDescriptor list.
_VALUE_TYPE_TO_SEMANTIC: dict[str, str] = {
    "integer": "i",
    "float": "f",
    "string": "s",
    "vector": "v",
    "rotation": "r",
    "boolean": "b",
    "asset": "a",
    "key": "k",
    "string-csv": "C",
    "string-map": "M",
}


@dataclasses.dataclass(frozen=True)
class BuilderMethodParam:
    name: str
    type: BuilderParamType


@dataclasses.dataclass(frozen=True)
class BuilderMethod:
    # `face_target` and `nullable` are SPP-flavored
    name: str
    """Final, already-resolved method name on the builder class."""
    rule_name: str
    """Owning ruleset rule, prefix stripped (e.g. `COLOR` or `TYPE`)"""
    rule_tag: int
    """Int value of `rule_name`"""
    variant_tag: int | None
    """`None` for non-variant rules, int value of the variant constant otherwise"""
    face_target: bool
    nullable: bool
    params: list[BuilderMethodParam]


@dataclasses.dataclass(frozen=True)
class BuilderSpec:
    class_name: str
    methods: list[BuilderMethod]


@dataclasses.dataclass(frozen=True)
class MemberDescriptor:
    """Descriptor for a single property in an enum-membership-derived builder."""

    strict_name: str
    """Always-valid property name (prefix stripped, lowercased)."""
    pretty_name: str | None
    """Pretty alias, or None if reverted due to collision."""
    tag: int
    """Numeric value of the originating constant (the rule tag)."""
    value_type: str
    """Semantic type from the value-type annotation (e.g. 'float', 'vector')."""


def _method_name(*parts: str) -> str:
    # ("COLOR",) -> "color", ("GLTF_BASE_COLOR",) -> "gltfBaseColor";
    # ("PRIM_", "TYPE", "BOX") -> "primTypeBox".
    words = [w for p in parts for w in p.split("_") if w]
    return words[0].lower() + "".join(w.capitalize() for w in words[1:])


def _build_params(raw_params: list[tuple[str, str]]) -> list[BuilderMethodParam]:
    """`raw_params` comes from YAML as a list of `[type_name, arg_name]` pairs."""
    return [
        BuilderMethodParam(name=arg_name, type=_RULESET_TYPES[type_name])
        for type_name, arg_name in raw_params
    ]


def expand_builder(lsl: LSLDefinitions, ruleset_name: str, class_name: str) -> BuilderSpec:
    """Expand any named builder-ruleset into a BuilderSpec.

    LSL-side semantic validation is assumed to have already run via
    LSLDefinitionParser._validate_builder_rule_variants.
    """
    ruleset = lsl.builder_rulesets[ruleset_name]
    rule_enum = lsl.enums[ruleset["enum"]]

    methods: list[BuilderMethod] = []
    for rule_name, rule in ruleset["rules"].items():
        face_target = bool(rule.get("face-target"))
        nullable = bool(rule.get("nullable"))
        rule_tag = rule_enum.by_name[rule_name].value

        if rule.get("variants"):
            variant_enum = lsl.enums[rule["variant-enum"]]
            for variant in rule["variants"]:
                for variant_name in variant["applies-to"]:
                    methods.append(
                        BuilderMethod(
                            name=_method_name(rule_enum.prefix, rule_name, variant_name),
                            rule_name=rule_name,
                            rule_tag=rule_tag,
                            variant_tag=variant_enum.by_name[variant_name].value,
                            face_target=face_target,
                            nullable=nullable,
                            params=_build_params(variant["params"]),
                        )
                    )
        else:
            methods.append(
                BuilderMethod(
                    name=rule.get("method-name") or _method_name(rule_name),
                    rule_name=rule_name,
                    rule_tag=rule_tag,
                    variant_tag=None,
                    face_target=face_target,
                    nullable=nullable,
                    params=_build_params(rule["params"]),
                )
            )
    return BuilderSpec(
        # The "class name" is global, so we don't want it to be ambiguous
        class_name=class_name,
        methods=methods,
    )


def expand_spp_builder(lsl: LSLDefinitions) -> BuilderSpec:
    """Compatibility wrapper. Expands the prim-params ruleset into the SPP builder."""
    return expand_builder(lsl, "prim-params", "PrimParamsSetterType")


def expand_member_params(
    lsl: LSLDefinitions,
    enum_name: str,
    filler_tokens: set[str],
) -> list[MemberDescriptor]:
    """Derive a sorted, collision-resolved list of property descriptors from
    the constants that are members of *enum_name*.

    Pass 1 produces strict names by stripping the enum prefix and lowercasing.
    Pass 2 produces pretty aliases by removing *filler_tokens*.
    If two pretty aliases collide, both revert to their strict names.
    Fails hard if any two strict names are identical.
    """
    enum = lsl.enums[enum_name]
    candidates = sorted(
        (
            c
            for c in lsl.constants.values()
            if any(e.name == enum_name for e in c.member_of) and not c.private
        ),
        key=lambda c: int(c.value, 0),
    )

    rows: list[tuple] = []
    for const in candidates:
        name = const.name
        prefix = enum.prefix
        strict = (name[len(prefix) :] if name.startswith(prefix) else name).lower()
        if const.value_type is None:
            raise ValueError(
                f"Constant {const.name!r} is a member of {enum_name!r} "
                f"but has no value-type annotation."
            )
        rows.append((strict, int(const.value, 0), const.value_type, const.pretty_name))

    # Hard-fail on strict name collisions (implies a data error).
    strict_names = [r[0] for r in rows]
    dupes = {n for n in strict_names if strict_names.count(n) > 1}
    if dupes:
        raise ValueError(f"Strict name collision(s) in {enum_name}: {sorted(dupes)}")

    # Pass 2: pretty aliases.
    # A constant's pretty_name field takes priority over the filler-token derivation.
    def _pretty(strict: str, override: str | None) -> str:
        if override is not None:
            return override
        tokens = [t for t in strict.split("_") if t not in filler_tokens]
        return "_".join(tokens) if tokens else strict

    pretties = [_pretty(strict, override) for strict, _, _, override in rows]

    # Hard-fail if any pretty name is duplicated and at least one side is an explicit
    # override (author error — cannot silently revert an intentional name).
    pretty_counts: dict[str, int] = {}
    for p in pretties:
        pretty_counts[p] = pretty_counts.get(p, 0) + 1
    for (_, _, _, override), p in zip(rows, pretties):
        if pretty_counts[p] > 1 and override is not None:
            raise ValueError(
                f"pretty-name collision in {enum_name}: '{p}' is used by multiple constants"
            )

    # Auto-derived names that collide revert to strict names instead of erroring.
    colliding = {
        p
        for (_, _, _, override), p in zip(rows, pretties)
        if override is None and pretty_counts[p] > 1
    }

    return [
        MemberDescriptor(
            strict_name=strict,
            pretty_name=None if (override is None and pretty in colliding) else pretty,
            tag=tag,
            value_type=vt,
        )
        for (strict, tag, vt, override), pretty in zip(rows, pretties)
    ]


def expand_table_ruleset(lsl: LSLDefinitions, ruleset_name: str) -> list[MemberDescriptor]:
    """Expand a type:table builder-ruleset into a sorted property descriptor list.

    Reads ``enum`` and ``filler-tokens`` from the yaml entry.
    """
    ruleset = lsl.builder_rulesets[ruleset_name]
    enum_name = ruleset["enum"]
    filler_tokens = set(ruleset.get("filler-tokens", []))
    return expand_member_params(lsl, enum_name, filler_tokens)
