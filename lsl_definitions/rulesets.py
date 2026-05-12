"""
Ruleset-to-Luau codegen. Currently the only ruleset modeled is `prim-params`,
expanded into the fluent SPP builder.
"""

from __future__ import annotations

import dataclasses
from typing import TYPE_CHECKING, Dict, List, Optional, Tuple

if TYPE_CHECKING:
    from lsl_definitions.lsl import LSLDefinitions


@dataclasses.dataclass(frozen=True)
class BuilderParamType:
    """Abstract user-facing input type, maps to a Luau type definition"""

    name: str
    luau_type: str


_RULESET_TYPES: Dict[str, BuilderParamType] = {
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
    variant_tag: Optional[int]
    """`None` for non-variant rules, int value of the variant constant otherwise"""
    face_target: bool
    nullable: bool
    params: List[BuilderMethodParam]


@dataclasses.dataclass(frozen=True)
class BuilderSpec:
    class_name: str
    methods: List[BuilderMethod]


def _method_name(*parts: str) -> str:
    # ("COLOR",) -> "color", ("GLTF_BASE_COLOR",) -> "gltfBaseColor";
    # ("PRIM_", "TYPE", "BOX") -> "primTypeBox".
    words = [w for p in parts for w in p.split("_") if w]
    return words[0].lower() + "".join(w.capitalize() for w in words[1:])


def _build_params(raw_params: List[Tuple[str, str]]) -> List[BuilderMethodParam]:
    """`raw_params` comes from YAML as a list of `[type_name, arg_name]` pairs."""
    return [
        BuilderMethodParam(name=arg_name, type=_RULESET_TYPES[type_name])
        for type_name, arg_name in raw_params
    ]


def expand_spp_builder(lsl: "LSLDefinitions") -> BuilderSpec:
    # Translates the `prim-params` ruleset into SLua builder methods. The
    # LSL-side semantic validation already ran in
    # `LSLDefinitionParser._validate_builder_rule_variants`.
    ruleset = lsl.builder_rulesets["prim-params"]
    rule_enum = lsl.enums[ruleset["enum"]]

    methods: List[BuilderMethod] = []
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
        class_name="PrimParamsSetterType",
        methods=methods,
    )
