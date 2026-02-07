"""LSL (Linden Scripting Language) data models and parser."""

from __future__ import annotations

import dataclasses
import enum
import re
from typing import TYPE_CHECKING, Dict, List, NamedTuple, Optional, Set, Union

import llsd
import yaml

from lsl_definitions.utils import StringEnum, remove_worthless

if TYPE_CHECKING:
    from lsl_definitions.slua import SLuaDefinitions


class LSLType(StringEnum):
    VOID = "void"
    INTEGER = "integer"
    FLOAT = "float"
    STRING = "string"
    KEY = "key"
    VECTOR = "vector"
    ROTATION = "rotation"
    LIST = "list"

    @property
    def meta(self) -> "LSLTypeMeta":
        return _TYPE_META_MAP[self]


class LSLTypeMeta(NamedTuple):
    cil_name: str
    lso_size: int
    lst_name: str
    cpp_name: str
    library_abbr: str
    cs_name: str
    mono_bind_name: str
    slua_name: str


_CS_TYPE_MODULE = "[ScriptTypes]LindenLab.SecondLife"


_TYPE_META_MAP: Dict[LSLType, LSLTypeMeta] = {
    LSLType.VOID: LSLTypeMeta(
        cil_name="void",
        lso_size=0,
        lst_name="LST_NULL",
        cpp_name="<wont happen>",
        library_abbr="",
        cs_name="void",
        mono_bind_name="void",
        slua_name="()",
    ),
    LSLType.INTEGER: LSLTypeMeta(
        cil_name="int32",
        lso_size=4,
        lst_name="LST_INTEGER",
        cpp_name="int32_t",
        library_abbr="i",
        cs_name="int",
        mono_bind_name="S32",
        slua_name="number",
    ),
    LSLType.FLOAT: LSLTypeMeta(
        cil_name="float",
        lso_size=4,
        lst_name="LST_FLOATINGPOINT",
        cpp_name="float",
        library_abbr="f",
        cs_name="float",
        mono_bind_name="F32",
        slua_name="number",
    ),
    LSLType.STRING: LSLTypeMeta(
        cil_name="string",
        lso_size=4,
        lst_name="LST_STRING",
        cpp_name="char *",
        library_abbr="s",
        cs_name="string",
        mono_bind_name="MonoStringType",
        slua_name="string",
    ),
    LSLType.KEY: LSLTypeMeta(
        cil_name=f"valuetype {_CS_TYPE_MODULE}.Key",
        lso_size=4,
        lst_name="LST_KEY",
        cpp_name="<wont happen>",
        library_abbr="k",
        cs_name="Key",
        mono_bind_name="MonoKeyType",
        slua_name="uuid",
    ),
    LSLType.VECTOR: LSLTypeMeta(
        cil_name=f"class {_CS_TYPE_MODULE}.Vector",
        lso_size=4 * 3,
        lst_name="LST_VECTOR",
        cpp_name="LLVector3",
        library_abbr="v",
        cs_name="Vector",
        mono_bind_name="MonoVectorType",
        slua_name="vector",
    ),
    LSLType.ROTATION: LSLTypeMeta(
        cil_name=f"class {_CS_TYPE_MODULE}.Quaternion",
        lso_size=4 * 4,
        lst_name="LST_QUATERNION",
        cpp_name="LLQuaternion",
        library_abbr="q",
        cs_name="Quaternion",
        mono_bind_name="MonoQuaternionType",
        slua_name="quaternion",
    ),
    LSLType.LIST: LSLTypeMeta(
        cil_name="class [mscorlib]System.Collections.ArrayList",
        lso_size=4,
        lst_name="LST_LIST",
        cpp_name="<wont happen>",
        library_abbr="l",
        cs_name="ArrayList",
        mono_bind_name="MonoListType",
        slua_name="list",
    ),
}


class LSLConstant(NamedTuple):
    name: str
    type: LSLType
    slua_type: Optional[str]
    slua_removed: bool
    value: str
    tooltip: str
    deprecated: bool
    private: bool
    """Whether this should this be included in the syntax file"""

    @property
    def value_raw(self) -> str:
        """My value, except that string escape sequences have been decoded"""
        import ast

        if self.type != LSLType.STRING:
            return self.value
        # convert unicode escapes from Luau format to Python format
        python_literal = re.sub(r"\\u\{([a-fA-F0-9]+)\}", r"\\u\1", f'"{self.value}"')
        # Decode escape sequences
        return ast.literal_eval(python_literal)

    @property
    def lsl_doc_literal(self) -> str:
        """My value as a LSL literal, except strings might have luau escape sequences for readability"""
        if self.type in {LSLType.STRING, LSLType.KEY}:
            return f'"{self.value}"'
        else:
            return self.value

    @property
    def slua_literal(self) -> str:
        """My value as a SLua literal"""
        if self.type == LSLType.KEY or self.slua_type == "uuid":
            return f"uuid({self.lsl_doc_literal})"
        elif self.type == LSLType.VECTOR:
            return f"vector({self.value[1:-1]})"
        elif self.type == LSLType.ROTATION:
            return f"rotation({self.value[1:-1]})"
        else:
            return self.lsl_doc_literal

    def to_dict(self) -> dict:
        return remove_worthless(
            {
                "deprecated": self.deprecated,
                # Will always use a <string> node, but that's fine for our purposes.
                # That's already the case for vector and hex int constants, anyway.
                "tooltip": self.tooltip,
                "type": str(self.type),
                "value": self.lsl_doc_literal,
            }
        )

    # TODO: This is a bit smelly, move it to `SLuaDefinitions`.
    def to_slua_dict(self, slua: "SLuaDefinitions") -> dict:
        try:
            return remove_worthless(
                {
                    "deprecated": self.deprecated,
                    # Will always use a <string> node, but that's fine for our purposes.
                    # That's already the case for vector and hex int constants, anyway.
                    "tooltip": self.tooltip,
                    "type": slua.validate_type(self.slua_type or self.type.meta.slua_name),
                    "value": self.slua_literal,
                }
            )
        except Exception as e:
            raise ValueError(f"In constant {self.name}: {e}") from e


@dataclasses.dataclass
class LSLArgument:
    name: str
    type: LSLType
    slua_type: Optional[str]
    tooltip: str
    index_semantics: bool
    asset_semantics: bool
    """Represents an asset name or uuid"""
    bool_semantics: bool
    """Represents a boolean"""

    def compute_slua_type(self) -> str:
        if self.slua_type is not None:
            return self.slua_type
        if self.asset_semantics and self.type == LSLType.STRING:
            return "string | uuid"
        if self.bool_semantics and self.type == LSLType.INTEGER:
            return "boolean | number"
        return self.type.meta.slua_name


@dataclasses.dataclass
class LSLEvent:
    name: str
    arguments: List[LSLArgument]
    tooltip: str
    private: bool
    deprecated: bool
    slua_deprecated: bool
    slua_removed: bool
    detected_semantics: bool

    def to_dict(self) -> dict:
        return remove_worthless(
            {
                "deprecated": self.deprecated,
                "arguments": [
                    {
                        a.name: {
                            "tooltip": a.tooltip,
                            "type": str(a.type),
                        }
                    }
                    for a in self.arguments
                ],
                "tooltip": self.tooltip,
            }
        )

    def to_slua_dict(self, slua: "SLuaDefinitions") -> dict:
        try:
            if self.detected_semantics:
                arguments = [
                    {
                        "detected": {
                            "tooltip": "Array of detected events.",
                            "type": slua.validate_type("{DetectedEvent}"),
                        }
                    }
                ]
            else:
                arguments = [
                    {
                        a.name: {
                            "tooltip": a.tooltip,
                            "type": slua.validate_type(a.compute_slua_type()),
                        }
                    }
                    for a in self.arguments
                ]
            return remove_worthless(
                {
                    "deprecated": self.deprecated or self.slua_deprecated,
                    "arguments": arguments,
                    "tooltip": self.tooltip,
                }
            )
        except Exception as e:
            raise ValueError(f"In event {self.name}: {e}") from e


@dataclasses.dataclass
class LSLFunction:
    name: str
    energy: float
    sleep: float
    ret_type: LSLType
    slua_type: Optional[str]
    god_mode: bool
    index_semantics: bool
    bool_semantics: bool
    detected_semantics: bool
    type_arguments: List[str]
    arguments: List[LSLArgument]
    tooltip: str
    private: bool
    """
    Whether or not to include this in the public-facing syntax LLSD.

    Might be useful for cases where you're intending to push an un-finalized
    implementation to Agni and don't want people to use it yet.
    """
    deprecated: bool
    slua_deprecated: bool
    slua_removed: bool
    """Only exists in llcompat"""
    func_id: int
    pure: bool
    """
    Whether or not the function is guaranteed side-effect free and pure

    For example, llFrand() is side-effect free, but not pure. llAsin()
    is generally pure, but might have the side-effect of setting a math error
    for certain inputs.

    pure functions may optionally be constant-folded during compilation,
    and we expect that the implementations live in `lscript_library` rather
    than `newsim` so that they can be unit tested by our LSL testing harness.
    """
    must_use: bool
    """Emit a warning if the return value is not used.
    See https://kampfkarren.github.io/selene/usage/std.html#must_use."""
    native: bool
    """
    Whether the function must have a native implementation for non-LSO VMs

    For example, it makes no sense to pass through the lscript interface for llList2String(),
    so it should have a native implementation in whichever VM. This mostly controls
    whether or not to generate binding code for Mono, and should rarely be set to
    true for new functions, unless you really want to write some C#. :)
    """

    mono_sleep: float
    """Mono-specific sleep value, only used for legacy functions that had mismatched sleeps"""

    def to_dict(self, include_internal: bool = False) -> dict:
        return remove_worthless(
            {
                "arguments": [
                    {
                        a.name: {
                            "tooltip": a.tooltip,
                            "type": str(a.type),
                        }
                    }
                    for a in self.arguments
                ],
                "deprecated": self.deprecated,
                "energy": self.energy,
                "god-mode": self.god_mode,
                "return": str(self.ret_type),
                "sleep": self.sleep,
                "tooltip": self.tooltip,
                "bool_semantics": self.bool_semantics,
                **(
                    {}
                    if not include_internal
                    else {
                        "func-id": self.func_id,
                        "private": self.private,
                        "pure": self.pure,
                        "must-use": self.must_use,
                        "native": self.native,
                        "mono-sleep": self.mono_sleep,
                        "index-semantics": self.index_semantics,
                    }
                ),
            }
        )

    def compute_slua_name(self, with_module=True) -> str:
        if not self.name.startswith("ll"):
            raise ValueError(f"invalid function name: {self.name}")
        if with_module:
            return self.name[:2] + "." + self.name[2:]
        else:
            return self.name[2:]

    def compute_slua_type(self, llcompat=False) -> str:
        if self.slua_type is not None:
            return self.slua_type
        if not llcompat and self.bool_semantics and self.ret_type == LSLType.INTEGER:
            return "boolean"
        return self.ret_type.meta.slua_name

    def to_slua_dict(self, slua: "SLuaDefinitions") -> dict:
        try:
            known_types = slua.validate_type_params(self.type_arguments)
            return remove_worthless(
                {
                    "type-arguments": self.type_arguments,
                    "arguments": [
                        {
                            a.name: {
                                "tooltip": a.tooltip,
                                "type": slua.validate_type(a.compute_slua_type(), known_types),
                            }
                        }
                        for a in self.arguments
                    ],
                    "deprecated": self.deprecated
                    or self.slua_deprecated
                    or self.slua_removed
                    or self.detected_semantics,
                    "energy": self.energy,
                    "god-mode": self.god_mode,
                    "return": slua.validate_type(self.compute_slua_type(), known_types),
                    "sleep": self.sleep,
                    "tooltip": self.tooltip,
                }
            )
        except Exception as e:
            raise ValueError(f"In function {self.name}: {e}") from e


class LSLDefinitions(NamedTuple):
    events: Dict[str, LSLEvent]
    functions: Dict[str, LSLFunction]
    constants: Dict[str, LSLConstant]
    controls: dict
    types: dict

    @property
    def reserved_words(self) -> Set[str]:
        """Words that may not be used as identifiers (case-sensitive)"""
        return (
            set(self.controls.keys())
            | set(self.types.keys())
            | {"class", "struct", "typeof", "valuetype"}
        )


class LSLFunctionRanges(enum.IntEnum):
    SCRIPT_ID_ANIMATION_STATES = 500
    SCRIPT_ID_JSON = 510
    SCRIPT_ID_MAINT = 520
    UNIFORM_SCALE_OPERATIONS = 590
    SCRIPT_ID_EXPERIENCE_TOOLS = 600
    SCRIPT_ID_LINKSETKVP = 650
    SCRIPT_ID_ENVIRONMENT = 700
    SCRIPT_ID_EMAIL_ADDITIONS = 750
    SCRIPT_ID_GLTF_MATERIALS = 760
    SCRIPT_ID_LIST_ADDITIONS = 800


class LSLDefinitionParser:
    def __init__(self):
        self._definitions = LSLDefinitions({}, {}, {}, {}, {})

    def parse_file(self, name: str) -> LSLDefinitions:
        if name.endswith(".llsd"):
            return self.parse_llsd_file(name)
        return self.parse_yaml_file(name)

    def parse_yaml_file(self, name: str):
        with open(name, "rb") as f:
            return self._parse_dict(yaml.safe_load(f.read()))

    def parse_llsd_file(self, name: str) -> LSLDefinitions:
        with open(name, "rb") as f:
            return self.parse_llsd_blob(f.read())

    def parse_llsd_blob(self, llsd_blob: bytes) -> LSLDefinitions:
        return self._parse_dict(llsd.parse_xml(llsd_blob))

    def _parse_dict(self, def_dict: dict) -> LSLDefinitions:
        if any(x for x in self._definitions):
            raise RuntimeError("Already parsed!")

        # Load these first so that we can use them to check reserved words
        self._definitions.controls.update(def_dict["controls"])
        self._definitions.types.update(def_dict["types"])

        seen_func_ids = set()
        for event_name, event_data in def_dict["events"].items():
            self._handle_event(event_name, event_data)
        for func_name, func_data in def_dict["functions"].items():
            func = self._handle_function(func_name, func_data)
            if func.func_id in seen_func_ids:
                raise ValueError(f"Func ID {func.func_id} was re-used by {func!r}")
            seen_func_ids.add(func.func_id)
        for const_name, const_data in def_dict["constants"].items():
            if const_name == "default":
                # This isn't a real constant, but it's in here for some reason, maybe syntax highlighting?
                continue
            self._handle_constant(const_name, const_data)

        return self._definitions

    def _handle_event(self, event_name: str, event_data: dict) -> LSLEvent:
        self._validate_identifier(event_name)
        event = LSLEvent(
            name=event_name,
            tooltip=event_data.get("tooltip", ""),
            arguments=[
                self._handle_argument(event_name, arg)
                for arg in (event_data.get("arguments") or [])
            ],
            private=event_data.get("private", False),
            deprecated=event_data.get("deprecated", False),
            slua_deprecated=event_data.get("slua-deprecated", False),
            slua_removed=event_data.get("slua-removed", False),
            detected_semantics=event_data.get("detected-semantics", False),
        )

        if event.name in self._definitions.events:
            raise KeyError(f"{event.name} is already defined")
        self._validate_args(event)

        self._definitions.events[event.name] = event
        return event

    def _handle_function(self, func_name: str, func_data: dict) -> LSLFunction:
        self._validate_identifier(func_name)
        func = LSLFunction(
            name=func_name,
            tooltip=func_data.get("tooltip", ""),
            # These do actually need to be floats.
            energy=float(func_data["energy"] or "0.0"),
            sleep=float(func_data["sleep"] or "0.0"),
            # 99.9% of the time this won't be specified, if it isn't, just use `sleep`'s value.
            mono_sleep=float(func_data.get("mono-sleep", func_data.get("sleep")) or "0.0"),
            ret_type=LSLType(func_data["return"]),
            slua_type=func_data.get("slua-return", None),
            type_arguments=func_data.get("type-arguments", []),
            arguments=[
                self._handle_argument(func_name, arg) for arg in (func_data.get("arguments") or [])
            ],
            private=func_data.get("private", False),
            god_mode=func_data.get("god-mode", False),
            deprecated=func_data.get("deprecated", False),
            slua_deprecated=func_data.get("slua-deprecated", False),
            slua_removed=func_data.get("slua-removed", False),
            func_id=func_data["func-id"],
            pure=func_data.get("pure", False),
            must_use=func_data.get("must-use", False),
            native=func_data.get("native", False),
            index_semantics=bool(func_data.get("index-semantics", False)),
            bool_semantics=bool(func_data.get("bool-semantics", False)),
            detected_semantics=bool(func_data.get("detected-semantics", False)),
        )

        if func.name in self._definitions.functions:
            raise KeyError(f"{func.name} is already defined")

        if func.index_semantics and func.ret_type not in (LSLType.INTEGER, LSLType.LIST):
            raise ValueError(
                f"{func.name} has ret with index semantics, but ret type is {func.ret_type!r}"
            )
        if func.bool_semantics and func.ret_type not in (LSLType.INTEGER, LSLType.LIST):
            raise ValueError(
                f"{func.name} has ret with bool semantics, but ret type is {func.ret_type!r}"
            )

        if func.bool_semantics and func.index_semantics:
            raise ValueError(f"Can't have both bool and index semantics for {func.name}")

        self._validate_args(func)

        self._definitions.functions[func.name] = func
        return func

    @staticmethod
    def _handle_argument(func_name: str, arg_dict: dict) -> LSLArgument:
        if len(arg_dict) != 1:
            # Arguments are meant to be an array of single-element dicts to keep order.
            raise ValueError(f"Expected {func_name}'s {arg_dict!r} to only have one element")

        arg_name, arg_data = list(arg_dict.items())[0]
        arg = LSLArgument(
            name=arg_name,
            type=LSLType(arg_data["type"]),
            slua_type=arg_data.get("slua-type", None),
            asset_semantics=bool(arg_data.get("asset-semantics", False)),
            bool_semantics=bool(arg_data.get("bool-semantics", False)),
            index_semantics=bool(arg_data.get("index-semantics", False)),
            tooltip=arg_data.get("tooltip", ""),
        )
        if arg.asset_semantics and arg.type != LSLType.STRING:
            raise ValueError(
                f"{func_name}'s {arg_name} has asset semantics, but type is {arg.type!r}"
            )
        if arg.bool_semantics and arg.type != LSLType.INTEGER:
            raise ValueError(
                f"{func_name}'s {arg_name} has bool semantics, but type is {arg.type!r}"
            )
        if arg.index_semantics and arg.type != LSLType.INTEGER:
            raise ValueError(
                f"{func_name}'s {arg_name} has index semantics, but type is {arg.type!r}"
            )
        return arg

    def _validate_args(self, obj: Union[LSLEvent, LSLFunction]) -> None:
        unique_arg_names = set(a.name for a in obj.arguments)
        if len(unique_arg_names) != len(obj.arguments):
            raise KeyError(f"Duplicate argument names in {obj.name}")
        for name in unique_arg_names:
            self._validate_identifier(name)
        if obj.name.startswith("llDetected"):
            if not all(x.index_semantics for x in obj.arguments):
                raise ValueError(f"{obj.name} had argument without index semantics")

    _IDENTIFIER_RE = re.compile(r"\A[_a-zA-Z][_a-zA-Z0-9]*\Z")

    def _validate_identifier(self, name: str) -> None:
        if not re.match(self._IDENTIFIER_RE, name):
            raise KeyError(f"{name!r} is not a valid identifier")
        if name in self._definitions.reserved_words:
            raise KeyError(f"{name!r} is a reserved name")

    def _handle_constant(self, const_name: str, const_data: dict) -> LSLConstant:
        const = LSLConstant(
            name=const_name,
            type=LSLType(const_data["type"]),
            slua_type=const_data.get("slua-type", None),
            slua_removed=const_data.get("slua-removed", False),
            value=str(const_data["value"]),
            tooltip=const_data.get("tooltip", ""),
            private=const_data.get("private", False),
            deprecated=const_data.get("deprecated", False),
        )
        if const.type not in {"float", "integer", "string", "vector", "rotation"}:
            raise ValueError(f"Invalid constant type {const.type}")
        if const.name in self._definitions.constants:
            raise KeyError(f"{const.name} is already defined")
        self._definitions.constants[const.name] = const
        return const
