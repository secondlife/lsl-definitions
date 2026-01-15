#!/bin/env python3
# Importantly, this shebang line prevents the bytecode pre-compilation step from
# deciding that this script is Python 2. It is not.

import ast
import ctypes
import dataclasses
import enum
import itertools
import os.path
import re
import stat
import argparse
import uuid
import os
from typing import Iterable, NamedTuple, Dict, List, Set, Sequence, TypeVar, Union, Any

import llsd  # noqa
import yaml


def quoted_presenter(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style='"')


yaml.add_representer(uuid.UUID, quoted_presenter)


class StringEnum(str, enum.Enum):
    def __str__(self):
        return self.value


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
    ),
    LSLType.INTEGER: LSLTypeMeta(
        cil_name="int32",
        lso_size=4,
        lst_name="LST_INTEGER",
        cpp_name="int32_t",
        library_abbr="i",
        cs_name="int",
        mono_bind_name="S32",
    ),
    LSLType.FLOAT: LSLTypeMeta(
        cil_name="float",
        lso_size=4,
        lst_name="LST_FLOATINGPOINT",
        cpp_name="float",
        library_abbr="f",
        cs_name="float",
        mono_bind_name="F32",
    ),
    LSLType.STRING: LSLTypeMeta(
        cil_name="string",
        lso_size=4,
        lst_name="LST_STRING",
        cpp_name="char *",
        library_abbr="s",
        cs_name="string",
        mono_bind_name="MonoStringType",
    ),
    LSLType.KEY: LSLTypeMeta(
        cil_name=f"valuetype {_CS_TYPE_MODULE}.Key",
        lso_size=4,
        lst_name="LST_KEY",
        cpp_name="<wont happen>",
        library_abbr="k",
        cs_name="Key",
        mono_bind_name="MonoKeyType",
    ),
    LSLType.VECTOR: LSLTypeMeta(
        cil_name=f"class {_CS_TYPE_MODULE}.Vector",
        lso_size=4 * 3,
        lst_name="LST_VECTOR",
        cpp_name="LLVector3",
        library_abbr="v",
        cs_name="Vector",
        mono_bind_name="MonoVectorType",
    ),
    LSLType.ROTATION: LSLTypeMeta(
        cil_name=f"class {_CS_TYPE_MODULE}.Quaternion",
        lso_size=4 * 4,
        lst_name="LST_QUATERNION",
        cpp_name="LLQuaternion",
        library_abbr="q",
        cs_name="Quaternion",
        mono_bind_name="MonoQuaternionType",
    ),
    LSLType.LIST: LSLTypeMeta(
        cil_name="class [mscorlib]System.Collections.ArrayList",
        lso_size=4,
        lst_name="LST_LIST",
        cpp_name="<wont happen>",
        library_abbr="l",
        cs_name="ArrayList",
        mono_bind_name="MonoListType",
    ),
}


class LSLConstant(NamedTuple):
    name: str
    type: LSLType
    value: str
    tooltip: str
    deprecated: bool
    private: bool
    """Whether this should this be included in the syntax file"""

    def to_dict(self) -> dict:
        return _remove_worthless(
            {
                "tooltip": self.tooltip,
                # Will always use a <string> node, but that's fine for our purposes.
                # That's already the case for vector and hex int constants, anyway.
                "value": _escape_python(self.value),
                "type": str(self.type),
                "deprecated": self.deprecated,
            }
        )


@dataclasses.dataclass
class LSLArgument:
    name: str
    type: LSLType
    tooltip: str
    index_semantics: bool


@dataclasses.dataclass
class LSLEvent:
    name: str
    arguments: List[LSLArgument]
    tooltip: str
    private: bool
    deprecated: bool

    def to_dict(self) -> dict:
        return _remove_worthless(
            {
                "tooltip": self.tooltip,
                "deprecated": self.deprecated,
                "arguments": [
                    {
                        a.name: {
                            "type": str(a.type),
                            "tooltip": a.tooltip,
                        }
                    }
                    for a in self.arguments
                ],
            }
        )


@dataclasses.dataclass
class LSLFunction:
    name: str
    energy: float
    sleep: float
    ret_type: LSLType
    god_mode: bool
    index_semantics: bool
    bool_semantics: bool
    arguments: List[LSLArgument]
    tooltip: str
    private: bool
    """
    Whether or not to include this in the public-facing syntax LLSD.

    Might be useful for cases where you're intending to push an un-finalized
    implementation to Agni and don't want people to use it yet.
    """
    deprecated: bool
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
        return _remove_worthless(
            {
                "deprecated": self.deprecated,
                "god-mode": self.god_mode,
                "energy": self.energy,
                "sleep": self.sleep,
                "return": str(self.ret_type),
                "arguments": [
                    {
                        a.name: {
                            "type": str(a.type),
                            "tooltip": a.tooltip,
                        }
                    }
                    for a in self.arguments
                ],
                "tooltip": self.tooltip,
                "bool_semantics": self.bool_semantics,
                **(
                    {}
                    if not include_internal
                    else {
                        "func-id": self.func_id,
                        "private": self.private,
                        "pure": self.pure,
                        "native": self.native,
                        "mono-sleep": self.mono_sleep,
                    }
                ),
            }
        )


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


def _escape_python(val: str) -> str:
    """Encode a string with escapes according to repr() rules"""
    # Syntax files have double-encoded values :(
    return repr(repr(val)[1:-1])[1:-1]


def _unescape_python(val: str) -> str:
    """Decode a string with escapes as if it were a string literal"""
    if '"' in val:
        raise ValueError("Can't handle quotes here")
    return ast.literal_eval('"' + ast.literal_eval('"' + val + '"') + '"')


def _to_c_str(val: str) -> str:
    # Unicode characters should be replaced with hex escapes.
    repr_val = repr(val.encode("utf-8"))
    assert '"' not in repr_val
    # Need to slice off the leading 'b' as well.
    return repr_val[2:-1]


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
            arguments=[
                self._handle_argument(func_name, arg) for arg in (func_data.get("arguments") or [])
            ],
            private=func_data.get("private", False),
            god_mode=func_data.get("god-mode", False),
            deprecated=func_data.get("deprecated", False),
            func_id=func_data["func-id"],
            pure=func_data.get("pure", False),
            native=func_data.get("native", False),
            index_semantics=bool(func_data.get("index-semantics", False)),
            bool_semantics=bool(func_data.get("bool-semantics", False)),
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
            index_semantics=bool(arg_data.get("index-semantics", False)),
            tooltip=arg_data.get("tooltip", ""),
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
        self._validate_identifier(const_name)
        const = LSLConstant(
            name=const_name,
            type=LSLType(const_data["type"]),
            value=str(self._massage_const_value(const_data["value"])),
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

    @staticmethod
    def _massage_const_value(val: Any) -> Any:
        if not isinstance(val, str):
            return val
        # Unescape any Python-like string escapes in the code
        return _unescape_python(val)


def _to_f32(val: float) -> float:
    return ctypes.c_float(val).value


def _remove_worthless(val: dict) -> dict:
    """Remove attributes that have the same implied values when not present"""
    if not val.get("deprecated"):
        val.pop("deprecated", None)
    if not val.get("god-mode"):
        val.pop("god-mode", None)
    if not val.get("private"):
        val.pop("private", None)
    if not val.get("pure"):
        val.pop("pure", None)
    if not val.get("native"):
        val.pop("native", None)
    if not val.get("bool-semantics"):
        val.pop("bool-semantics", None)
    if not val.get("index-semantics"):
        val.pop("index-semantics", None)
    return val


def dump_syntax(definitions: LSLDefinitions) -> bytes:
    """Write a syntax file for use by viewers"""
    syntax = {
        "llsd-lsl-syntax-version": 2,
        "controls": definitions.controls.copy(),
        "types": definitions.types.copy(),
        "constants": {},
        "events": {},
        "functions": {},
    }
    for event in sorted(definitions.events.values(), key=lambda x: x.name):
        if event.private:
            continue
        syntax["events"][event.name] = event.to_dict()

    for func in sorted(definitions.functions.values(), key=lambda x: x.name):
        if func.private:
            continue
        syntax["functions"][func.name] = func.to_dict()

    # This one's a little weird because it's not a "real" constant, but it's expected to be in the
    # constants section even though it has no value or type. It allows default to have a tooltip
    # and a distinct color.
    syntax["constants"]["default"] = {
        "tooltip": "All scripts must have a default state, which is the first state entered when the script starts.\n"
        "If another state is defined before the default state, the compiler will report a syntax error."
    }

    for const in sorted(definitions.constants.values(), key=lambda x: x.name):
        if const.private:
            continue
        syntax["constants"][const.name] = const.to_dict()

    return llsd.format_xml(syntax)


def _write_if_different(filename: str, data: Union[bytes, str]):
    """
    Write, but not if it would change mtime needlessly

    That may mark a file dirty for build, which we don't want
    """
    if isinstance(data, str):
        data = data.encode("utf8")

    old_data = None
    if os.path.exists(filename) and stat.S_ISREG(os.stat(filename).st_mode):
        with open(filename, "rb") as f:
            old_data = f.read()

    if data != old_data:
        with open(filename, "wb") as f:
            f.write(data)


def gen_constant_lsl_script(definitions: LSLDefinitions) -> None:
    """
    Generate a script so constants' effective values can be determined

    This can be done by looking at the bytecode of the compiled script.
    """
    keys = ['"%s"' % x for x in definitions.constants.keys()]
    joined_names = ", \n".join(itertools.chain(*zip(keys, definitions.constants.keys())))

    # Generate some stub event handlers as well
    event_handlers = ""
    for event in definitions.events.values():
        event_handlers += f"{event.name}("
        event_handlers += ", ".join(f"{str(x.type)} _{i}" for i, x in enumerate(event.arguments))
        event_handlers += "){}\n"
    print("list l = [%s];\ndefault{\n%s\n}" % (joined_names, event_handlers))


def _splice(val: str, splice_by: str, replacement: str) -> str:
    split = val.split(splice_by, 1)
    if len(split) != 2:
        raise ValueError(f"Unable to splice by {splice_by!r}")
    return "\n".join((split[0], replacement, split[1]))


_LEXER_CONST_COMMENT = "/* GENERATED LEXER CONSTANTS */"
_LEXER_EVENT_COMMENT = "/* GENERATED LEXER EVENTS */"
_LEXER_COORD_TEMPLATE = '"%(name)s" { count(); return(%(name)s); }\n'
_LEXER_NUMERIC_TEMPLATE = '"%s" { count(); yylval.%sval = %s; return(%s); }\n'
_LEXER_STR_TEMPLATE = (
    '"%s" { yylval.sval = new char[%d]; strcpy(yylval.sval, "%s"); return(STRING_CONSTANT); }\n'
)
_LEXER_BLACKLIST = {
    # These are special in the lexer for inexplicable reasons.
    "TRUE",
    "FALSE",
    # These events have weird names :(
    "listen",
    "changed",
    "linkset_data",
    "on_rez",
}


def gen_lexer_file(definitions: LSLDefinitions, template_file: str, output_file: str):
    """Generate bits to include in indra.in.l"""
    with open(template_file, "r") as f:
        lexer_template = f.read()

    generated_events = ""
    for event in definitions.events.values():
        if event.name in _LEXER_BLACKLIST:
            continue
        generated_events += '"%s" { count(); return(%s); }\n' % (event.name, event.name.upper())
    lexer_template = _splice(lexer_template, _LEXER_EVENT_COMMENT, generated_events)

    generated_constants = ""
    for const in definitions.constants.values():
        if const.name in _LEXER_BLACKLIST:
            continue

        if const.type in (LSLType.VECTOR, LSLType.ROTATION):
            # We can't easily generate constant definitions for these, they
            # _must_ be manually defined in the parser as well. Just generate the boilerplate
            # to pull in their definition from the parser.
            generated_constants += _LEXER_COORD_TEMPLATE % {"name": const.name}
        elif const.type == LSLType.FLOAT:
            generated_constants += _LEXER_NUMERIC_TEMPLATE % (
                const.name,
                "f",
                const.value + "f",
                "FP_CONSTANT",
            )
        elif const.type == LSLType.INTEGER:
            generated_constants += _LEXER_NUMERIC_TEMPLATE % (
                const.name,
                "i",
                const.value,
                "INTEGER_CONSTANT",
            )
        elif const.type == LSLType.STRING:
            c_str = _to_c_str(const.value)
            c_str_len = len(const.value.encode("utf8")) + 1
            generated_constants += _LEXER_STR_TEMPLATE % (const.name, c_str_len, c_str)
        else:
            raise ValueError(f"Unknown constant type {const.type!r}")
    lexer_template = _splice(lexer_template, _LEXER_CONST_COMMENT, generated_constants)

    _write_if_different(output_file, lexer_template)


_PARSER_EVENT_SWITCH_COMMENT = "/* GENERATED PARSER EVENT SWITCH */"
_PARSER_EVENT_TYPES_COMMENT = "/* GENERATED PARSER EVENT TYPES */"
_PARSER_EVENT_TOKENS_COMMENT = "/* GENERATED PARSER EVENT TOKENS */"
_PARSER_EVENT_DEFINITIONS_COMMENT = "/* GENERATED PARSER EVENT DEFINITIONS */"

# These have weird idiosyncrasies in their existing naming conventions, don't generate.
_PARSER_TYPES_BLACKLIST = {
    "listen",
    "on_rez",
    "linkset_data",
    "changed",
}
_PARSER_DEFINITIONS_BLACKLIST = {
    "listen",
    "on_rez",
    "linkset_data",
    "changed",
    "at_target",
    "not_at_target",
    "at_rot_target",
    "not_at_rot_target",
    "run_time_permissions",
    "experience_permissions",
    "experience_permissions_denied",
    "remote_data",
}


def _event_to_class_name(event: LSLEvent) -> str:
    return event.name.title().replace("_", "").replace("Http", "HTTP")


def gen_parser_file(definitions: LSLDefinitions, template_file: str, output_file: str):
    """Generate bits to include in indra.in.y"""
    with open(template_file, "r") as f:
        parser_template: str = f.read()

    generated_event_tokens = ""
    generated_event_types = ""
    generated_event_definitions = ""
    generated_event_switch = ""

    for event in definitions.events.values():
        if event.name not in _PARSER_TYPES_BLACKLIST:
            generated_event_tokens += f"%token    {event.name.upper()}\n"
            generated_event_types += f"%type<event>    {event.name}\n"
            generated_event_switch += (
                """
    | %s compound_statement {
        $$ = new LLScriptEventHandler(gLine, gColumn, $1, $2);
        gAllocationManager->addAllocation($$);
    }
"""
                % event.name
            )
        if event.name not in _PARSER_DEFINITIONS_BLACKLIST:
            generated_event_definitions += f"{event.name}\n"
            generated_event_definitions += f"    : {event.name.upper()} '(' "

            # Generate the header with args
            first_arg = True
            for arg in event.arguments:
                if not first_arg:
                    generated_event_definitions += " ',' "
                type_token = str(arg.type).upper()
                type_token = {
                    "KEY": "LLKEY",
                    "ROTATION": "QUATERNION",
                }.get(type_token, type_token)
                generated_event_definitions += f"{type_token} IDENTIFIER "
                first_arg = False
            generated_event_definitions += " ')'\n    {\n"

            # Now for the body
            arg_idx = 4
            for i, arg in enumerate(event.arguments):
                generated_event_definitions += f"""
        LLScriptIdentifier	*id{i} = new LLScriptIdentifier(gLine, gColumn, ${arg_idx});
        gAllocationManager->addAllocation(id{i});
"""
                arg_idx += 3

            event_class = _event_to_class_name(event)
            arg_str = ", ".join("id%d" % x for x in range(0, len(event.arguments)))
            if arg_str:
                arg_str = ", " + arg_str
            generated_event_definitions += (
                f"        $$ = new LLScript{event_class}Event(gLine, gColumn{arg_str});\n"
            )

            generated_event_definitions += "    }\n    ;\n\n"

    parser_template = _splice(parser_template, _PARSER_EVENT_TOKENS_COMMENT, generated_event_tokens)
    parser_template = _splice(parser_template, _PARSER_EVENT_TYPES_COMMENT, generated_event_types)
    parser_template = _splice(parser_template, _PARSER_EVENT_SWITCH_COMMENT, generated_event_switch)
    parser_template = _splice(
        parser_template, _PARSER_EVENT_DEFINITIONS_COMMENT, generated_event_definitions
    )

    _write_if_different(output_file, parser_template)


def _arg_to_member_name(arg: LSLArgument) -> str:
    if arg.name[0].upper() != arg.name[0]:
        return "m" + arg.name.title().replace("_", "")
    # Probably already title case.
    return "m" + arg.name


_TREE_BLACKLIST = {
    # Basically everything, except state_entry() and game_control(),
    # New events are not meant to be in here, this is just meant to reduce
    # a huge diff churn.
    "link_message",
    "touch_start",
    "dataserver",
    "transaction_result",
    "at_target",
    "experience_permissions_denied",
    "http_response",
    "not_at_rot_target",
    "at_rot_target",
    "remote_data",
    "path_update",
    "listen",
    "money",
    "email",
    "run_time_permissions",
    "not_at_target",
    "http_request",
    "collision_start",
    "land_collision_end",
    "no_sensor",
    "state_exit",
    "object_rez",
    "experience_permissions",
    "collision",
    "linkset_data",
    "collision_end",
    "attach",
    "touch",
    "timer",
    "changed",
    "sensor",
    "moving_start",
    "touch_end",
    "land_collision",
    "control",
    "on_rez",
    "land_collision_start",
    "moving_end",
}


_TREE_CLASS_DECL_TEMPLATE = """class LLScript%(class_name)sEvent : public LLScriptEvent
{
public:
    LLScript%(class_name)sEvent(S32 line, S32 col%(constructor_args)s)
        : LLScriptEvent(line, col, LSTT_%(event_upper)s)
%(member_initializers)s
    {
    }

    ~LLScript%(class_name)sEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

%(members)s
};

"""


def gen_tree_header_file(definitions: LSLDefinitions, output_file: str) -> None:
    """Generate class declarations for event nodes to include in lscript_tree.h"""
    generated_tree_header = ""
    for event in definitions.events.values():
        if event.name in _TREE_BLACKLIST:
            continue
        constructor_args = "".join(f", LLScriptIdentifier *{x.name}" for x in event.arguments)
        member_initializers = "\n".join(
            f"        , {_arg_to_member_name(x)}({x.name})" for x in event.arguments
        )
        members = "\n".join(
            f"    LLScriptIdentifier *{_arg_to_member_name(x)};" for x in event.arguments
        )
        generated_tree_header += _TREE_CLASS_DECL_TEMPLATE % {
            "class_name": _event_to_class_name(event),
            "event_upper": event.name.upper(),
            "members": members,
            "member_initializers": member_initializers,
            "constructor_args": constructor_args,
        }
    _write_if_different(output_file, generated_tree_header)


_TREE_CLASS_DEF_TEMPLATE = """
void LLScript%(class_name)sEvent::recurse(
    LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg,
    LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk,
    LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
    if (gErrorToText.getErrors())
    {
        return;
    }
    switch(pass)
    {
    case LSCP_PRETTY_PRINT:
    case LSCP_EMIT_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "%(event_name)s( ");
%(emit_assembly)s
        fprintf(fp, " )\\n");
        break;
    case LSCP_SCOPE_PASS1:
      checkForDuplicateHandler(fp, this, scope, "%(event_name)s");
%(scope_pass1)s
        break;
    case LSCP_RESOURCE:
        {
            // we're just tryng to determine how much space the variable needs
            if (%(first_scope_entry)s)
            {
%(resource_scope_entries)s
            }
        }
        break;
    case LSCP_EMIT_BYTE_CODE:
        {
#ifdef LSL_INCLUDE_DEBUG_INFO
            char name[] = "%(event_name)s";
            chunk->addBytes(name, strlen(name) + 1);
%(event_debug_info)s
#endif
        }
        break;
    case LSCP_EMIT_CIL_ASSEMBLY:
        fdotabs(fp, tabs, tabsize);
        fprintf(fp, "%(event_name)s(");
%(emit_cil)s
        fprintf(fp, ")");
        break;
    default:
%(default_recurse)s
        break;
    }
}

S32 LLScript%(class_name)sEvent::getSize()
{
    return %(event_size)d;
}
"""

_RECURSE_BOILERPLATE = (
    "->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, "
    "chunk, heap, stacksize, entry, entrycount, NULL);"
)


def gen_tree_source_file(definitions: LSLDefinitions, output_file: str) -> None:
    """Generate implementations of event node methods for inclusion in lscript_tree.cpp"""
    generated_tree_source = ""
    for event in definitions.events.values():
        if event.name in _TREE_BLACKLIST:
            continue

        default_recurse = "\n".join(
            f"        {_arg_to_member_name(x)}{_RECURSE_BOILERPLATE};" for x in event.arguments
        )

        emit_cil = ""
        event_debug_info = ""
        resource_scope_entries = ""
        scope_pass1 = ""
        emit_assembly = ""
        first_scope_entry = None
        for arg in event.arguments:
            emit_cil += (
                f'        fprintf(fp, "{", " if emit_cil else ""}{arg.type.meta.cil_name} ");\n'
            )
            emit_cil += f"        {_arg_to_member_name(arg)}{_RECURSE_BOILERPLATE}\n"

            id_name = f"{_arg_to_member_name(arg)}->mName"
            event_debug_info += f"            chunk->addBytes({id_name}, strlen({id_name}) + 1);\n"

            id_scope_entry = f"{_arg_to_member_name(arg)}->mScopeEntry"
            if not first_scope_entry:
                first_scope_entry = id_scope_entry

            resource_scope_entries += f"                {id_scope_entry}->mOffset = (S32)count;\n"
            resource_scope_entries += (
                f"                {id_scope_entry}->mSize = {arg.type.meta.lso_size};\n"
            )
            resource_scope_entries += f"                count += {id_scope_entry}->mSize;\n"

            emit_assembly += (
                f'        fprintf(fp, "{", " if emit_assembly else ""}{arg.type!s} ");\n'
            )
            emit_assembly += f"        {_arg_to_member_name(arg)}{_RECURSE_BOILERPLATE}\n"

            member_name = _arg_to_member_name(arg)
            scope_pass1 += f"""
        if (scope->checkEntry({_arg_to_member_name(arg)}->mName))
        {{
            gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
        }}
        else
        {{
            {member_name}->mScopeEntry = scope->addEntry({member_name}->mName, LIT_VARIABLE, {arg.type.meta.lst_name});
        }}
"""

        if emit_cil:
            # If we emitted anything for arguments we need to emit a space before and after parens.
            emit_cil = '        fprintf(fp, " ");\n' + emit_cil
            emit_cil += '        fprintf(fp, " ");\n'

        generated_tree_source += _TREE_CLASS_DEF_TEMPLATE % {
            "class_name": _event_to_class_name(event),
            "event_name": event.name,
            "default_recurse": default_recurse,
            "event_size": sum(x.type.meta.lso_size for x in event.arguments),
            "first_scope_entry": first_scope_entry or "false",
            "resource_scope_entries": resource_scope_entries,
            "event_debug_info": event_debug_info,
            "emit_cil": emit_cil,
            "scope_pass1": scope_pass1,
            "emit_assembly": emit_assembly,
        }
    _write_if_different(output_file, generated_tree_source)


def gen_cpp_constants(definitions: LSLDefinitions, output_path: str) -> None:
    """Generate lllslconstants_generate.h so C++ can use our defined constants"""
    cpp_constants = "#pragma once\n\n// Generated file, do not edit directly!\n\n"

    for const in definitions.constants.values():
        # We don't want to generate these since they create a dependency on llmath
        # and their constexpr-ness is suspect.
        if const.type in (LSLType.ROTATION, LSLType.VECTOR):
            continue

        cpp_constants += f"constexpr {const.type.meta.cpp_name} LSL_GEN_{const.name.upper()} = "
        if const.type == LSLType.STRING:
            cpp_constants += f'"{_to_c_str(const.value)}"'
        elif const.type in (LSLType.INTEGER, LSLType.FLOAT):
            cpp_constants += const.value
        cpp_constants += ";\n"

    _write_if_different(output_path, cpp_constants)


_T = TypeVar("_T")


def _to_chunks(chunkable: Sequence[_T], chunk_size: int) -> Iterable[Sequence[_T]]:
    while chunkable:
        yield chunkable[:chunk_size]
        chunkable = chunkable[chunk_size:]


def gen_func_call_scripts(definitions: LSLDefinitions, output_path: str) -> None:
    """
    Generate a script that tries to call every function we know about

    Useful for verifying that a compiler agrees with our function definitions
    """

    # Ensure our output directory exists first
    os.makedirs(output_path, exist_ok=True)

    # Unfortunately, LSO scripts are the only things that actually use function IDs, which we need to test.
    # They're also limited to 16k. For that reason, we need to chunk the calls up between multiple scripts
    # so that we don't collide heap and stack when compiling.
    for i, chunk in enumerate(_to_chunks(list(definitions.functions.values()), 300)):
        func_calls = ""
        for func in chunk:
            if func.ret_type != LSLType.VOID:
                # Make this an assignment to a local so we can implicitly check the return value
                func_calls += func.ret_type.meta.library_abbr + " = "
            # Make a function call using locals of the appropriate type for the args
            func_calls += (
                f"{func.name}({', '.join(x.type.meta.library_abbr for x in func.arguments)});\n"
            )
        # Make a stub script with all the necessary function calls
        call_script = f"""
default {{
    state_entry() {{
        // These don't really matter, they just need to exist for the function calls to use.
        list l;
        integer i;
        float f;
        rotation q;
        key k;
        string s;
        vector v;
{func_calls}
    }}
}}
"""
        with open(os.path.join(output_path, f"func_calls_{i}.lsl"), "w") as f:
            f.write(call_script)


def gen_lscript_library_defs(definitions: LSLDefinitions, library_path: str):
    """
    Generate definitions to include in lscript_library.cpp

    Example:
    dangerousAddFunction(6, "llAbs", "i", "i", 10.0f, 0.0f, false);
    dangerousAddFunction(172, "llAcos", "f", "f", 10.0f, 0.0f, false);
    dangerousAddFunction(310, "llAddToLandBanList", "", "kf", 10.0f, 0.1f, false);
    """
    func_defs = ""
    for func in definitions.functions.values():
        if func.arguments:
            args_def = '"%s"' % "".join(x.type.meta.library_abbr for x in func.arguments)
        else:
            # Using `nullptr` instead of `""` saves a worthless array alloc inside `runllib_common()`.
            args_def = "nullptr"

        if func.ret_type == LSLType.VOID:
            # Using `nullptr` instead of `""` saves a worthless alloc inside `runllib_common()`.
            ret_def = "nullptr"
        else:
            ret_def = '"%s"' % func.ret_type.meta.library_abbr

        func_defs += (
            f'dangerousAddFunction({func.func_id}, "{func.name}", {ret_def}, {args_def}, '
            f"{func.energy}f, {func.sleep}f, {func.mono_sleep}f, {str(func.god_mode).lower()});\n"
        )

    _write_if_different(library_path, func_defs)


_MONO_CS_LIBRARY_DEFS_COMMENT = "/* GENERATED FUNCTION BINDINGS */"
# Everything we don't want to automatically generate function stubs for. This is pretty much every existing function,
# since we don't really know if they did anything weird in their implementation or definition (maybe differing
# energy / sleep values.) Better to leave them alone and only generate new functions.
# For testing, we omit from this blacklist `llAxisAngle2Rot` and `llListSortStrided`, and manually verify the output.
_OLD_FUNC_BLACKLIST = {
    "llGiveInventory",
    "llModPow",
    "llDetectedTouchNormal",
    "llNavigateTo",
    "llAddToLandPassList",
    "llGetScriptState",
    "llGetObjectDesc",
    "llPreloadSound",
    "llWind",
    "llCollisionFilter",
    "llGetVel",
    "llGetOwnerKey",
    "llGetNotecardLine",
    "llStopHover",
    "llGetInventoryName",
    "llJson2List",
    "llSay",
    "llGetAgentList",
    "llRequestAgentData",
    "llGetLinkSitFlags",
    "llJsonValueType",
    "llGetCameraRot",
    "llWorldPosToHUD",
    "llGetInventoryDesc",
    "llLinkSetSoundQueueing",
    "llGetEnvironment",
    "llGetInventoryPermMask",
    "llLinksetDataWrite",
    "llSetTextureAnim",
    "llCSV2List",
    "llGetMassMKS",
    "llAvatarOnSitTarget",
    "llCeil",
    "llCos",
    "llMapDestination",
    "llDetectedTouchPos",
    "llDetectedLinkNumber",
    "llReleaseControls",
    "llStopLookAt",
    "llEscapeURL",
    "llTriggerSoundLimited",
    "llSetParcelMusicURL",
    "llSetScriptState",
    "llRezObjectWithParams",
    "llStopPointAt",
    "llGetNumberOfNotecardLines",
    "llGetOwner",
    "llsRGB2Linear",
    "llGetGMTclock",
    "llGetStaticPath",
    "llLoadURL",
    "llInsertString",
    "llDeleteSubList",
    "llRot2Left",
    "llReturnObjectsByOwner",
    "llSubStringIndex",
    "llGetStatus",
    "llRemoteLoadScript",
    "llStopMoveToTarget",
    "llRound",
    "llParticleSystem",
    "llSensorRemove",
    "llSetContentType",
    "llGetAccel",
    "llLoopSoundMaster",
    "llRegionSay",
    "llGetSPMaxMemory",
    "llListFindStrided",
    "llGetRegionAgentCount",
    "llSetBuoyancy",
    "llDetectedType",
    "llSetPayPrice",
    "llSetRot",
    "llSetClickAction",
    "llSetLinkPrimitiveParams",
    "llLinksetDataWriteProtected",
    "llGroundNormal",
    "llLinkStopSound",
    "llList2ListStrided",
    "llReturnObjectsByID",
    "llList2String",
    "llWanderWithin",
    "llListStatistics",
    "llDetectedTouchBinormal",
    "llGetTexture",
    "llSetLinkCamera",
    "llEvade",
    "llGetRegionTimeDilation",
    "llCreateLink",
    "llGetCameraFOV",
    "llDetectedGrab",
    "llSameGroup",
    "llSetLinkAlpha",
    "llLinksetDataDelete",
    "llRot2Euler",
    "llGetDayOffset",
    "llTakeCamera",
    "llRequestSecureURL",
    "llGetAttached",
    "llRotateTexture",
    "llGetInventoryKey",
    "llSetSoundQueueing",
    "llList2Vector",
    "llTeleportAgent",
    "llSetExperienceKey",
    "llDialog",
    "llSetTorque",
    "llTargetedEmail",
    "llGetLinkName",
    "llGetParcelMusicURL",
    "llSetVehicleType",
    "llVecDist",
    "llGetPrimitiveParams",
    "llGetRegionMoonRotation",
    "llLinkSetSoundRadius",
    "llReplaceEnvironment",
    "llLinksetDataCountFound",
    "llListFindList",
    "llRequestDisplayName",
    "llGroundContour",
    "llGetParcelMaxPrims",
    "llClearExperience",
    "llList2Float",
    "llGetFreeURLs",
    "llRemoteLoadScriptPin",
    "llGetLinkNumber",
    "llGetAndResetTime",
    "llSleep",
    "llTransferLindenDollars",
    "llGetEnergy",
    "llGetKey",
    "llRequestUserKey",
    "llUnescapeURL",
    "llGetFreeMemory",
    "llFleeFrom",
    "llGetSimulatorHostname",
    "llGetMoonDirection",
    "llClearExperiencePermissions",
    "llLinksetDataDeleteFound",
    "llPassTouches",
    "llPursue",
    "llUnSit",
    "llGetUsername",
    "llGetLinkKey",
    "llApplyImpulse",
    "llCreateCharacter",
    "llListFindListNext",
    "llSetScale",
    "llSetAgentEnvironment",
    "llSetEnvironment",
    "llGetTime",
    "llGetRegionDayOffset",
    "llKey2Name",
    "llMoveToTarget",
    "llRequestUsername",
    "llSetText",
    "llGetRot",
    "llGetDayLength",
    "llSetForce",
    "llSetVehicleFloatParam",
    "llGetRegionTimeOfDay",
    "llKeyCountKeyValue",
    "llSetSoundRadius",
    "llCreateKeyValue",
    "llGetAgentSize",
    "llAxes2Rot",
    "llDeleteSubString",
    "llReplaceSubString",
    "llAddToLandBanList",
    "llChar",
    "llDeleteCharacter",
    "llCollisionSound",
    "llMakeFire",
    "llName2Key",
    "llParseStringKeepNulls",
    "llGetDate",
    "llGetNotecardLineSync",
    "llGetMoonRotation",
    "llBase64ToInteger",
    "llGetClosestNavPoint",
    "llStringToBase64",
    "llTeleportAgentHome",
    "llLinksetDataListKeys",
    "llAdjustSoundVolume",
    "llMakeFountain",
    "llRemoveInventory",
    "llDetectedTouchUV",
    "llAllowInventoryDrop",
    "llSetObjectPermMask",
    "llXorBase64StringsCorrect",
    "llGetNumberOfSides",
    "llDetectedTouchFace",
    "llTarget",
    "llAcos",
    "llFrand",
    "llStopObjectAnimation",
    "llSetLinkColor",
    "llAbs",
    "llSetTimerEvent",
    "llGetExperienceList",
    "llDie",
    "llAngleBetween",
    "llSetPrimMediaParams",
    "llSetLinkMedia",
    "llGenerateKey",
    "llListRandomize",
    "llGetSubString",
    "llReleaseURL",
    "llGetRegionCorner",
    "llMakeSmoke",
    "llLinksetDataFindKeys",
    "llSetLinkTextureAnim",
    "llOrd",
    "llDetectedName",
    "llGetLinkMedia",
    "llGetAnimation",
    "llEjectFromLand",
    "llTeleportAgentGlobalCoords",
    "llTriggerSound",
    "llLinksetDataReadProtected",
    "llAsin",
    "llSqrt",
    "llGetListEntryType",
    "llRot2Up",
    "llSetStatus",
    "llAttachToAvatar",
    "llGetObjectDetails",
    "llSetCameraAtOffset",
    "llGetAlpha",
    "llBase64ToString",
    "llGetCreator",
    "llRequestInventoryData",
    "llHTTPResponse",
    "llDumpList2String",
    "llIntegerToBase64",
    "llGetRegionDayLength",
    "llRezObject",
    "llList2List",
    "llForceMouselook",
    "llGetTextureOffset",
    "llTargetOmega",
    "llDataSizeKeyValue",
    "llMD5String",
    "llReleaseCamera",
    "llGetSimStats",
    "llGetObjectPermMask",
    "llSendRemoteData",
    "llGetListLength",
    "llShout",
    "llStringTrim",
    "llAgentInExperience",
    "llGetExperienceDetails",
    "llGetRegionFlags",
    "llSetCameraParams",
    "llGetUsedMemory",
    "llLinksetDataAvailable",
    "llHash",
    "llRotLookAt",
    "llFabs",
    "llTakeControls",
    "llTan",
    "llApplyRotationalImpulse",
    "llTargetRemove",
    "llSetObjectDesc",
    "llSetSitText",
    "llGetAnimationOverride",
    "llSetMemoryLimit",
    "llClearCameraParams",
    "llLoopSound",
    "llGetPermissions",
    "llList2ListSlice",
    "llLinksetDataDeleteProtected",
    "llSetVehicleRotationParam",
    "llList2Key",
    "llFloor",
    "llGetStartParameter",
    "llSetPrimURL",
    "llLinkAdjustSoundVolume",
    "llVerifyRSA",
    "llRemoveFromLandPassList",
    "llSetInventoryPermMask",
    "llListSort",
    "llResetScript",
    "llKeysKeyValue",
    "llComputeHash",
    "llGetMaxScaleFactor",
    "llGroundSlope",
    "llStartAnimation",
    "llResetLandBanList",
    "llGetRootPosition",
    "llSetCameraEyeOffset",
    "llSHA256String",
    "llPassCollisions",
    "llStopAnimation",
    "llSetKeyframedMotion",
    "llLog",
    "llUpdateCharacter",
    "llGetObjectPrimCount",
    "llPlaySound",
    "llSetAnimationOverride",
    "llGetAgentLanguage",
    "llSoundPreload",
    "llSetHoverHeight",
    "llResetTime",
    "llGetLocalRot",
    "llJsonSetValue",
    "llSetLocalRot",
    "llMinEventDelay",
    "llGetParcelDetails",
    "llSensor",
    "llRefreshPrimURL",
    "llCloud",
    "llStringLength",
    "llStopSound",
    "llWater",
    "llRot2Axis",
    "llClearLinkMedia",
    "llResetAnimationOverride",
    "llSetAngularVelocity",
    "llSetRemoteScriptAccessPin",
    "llPow",
    "llGetExperienceErrorMessage",
    "llParseString2List",
    "llDetectedTouchST",
    "llList2Integer",
    "llLinksetDataReset",
    "llOwnerSay",
    "llGetInventoryType",
    "llGetWallclock",
    "llDetectedOwner",
    "llDetectedGroup",
    "llGetCameraPos",
    "llMakeExplosion",
    "llGetScriptName",
    "llSignRSA",
    "llScriptDanger",
    "llSetObjectName",
    "llRotTargetRemove",
    "llSetRenderMaterial",
    "llReplaceAgentEnvironment",
    "llGetOmega",
    "llBreakAllLinks",
    "llHTTPRequest",
    "llReadKeyValue",
    "llLinear2sRGB",
    "llUpdateKeyValue",
    "llSetPhysicsMaterial",
    "llHMAC",
    "llRegionSayTo",
    "llRequestSimulatorData",
    "llRemoveFromLandBanList",
    "llRemoteDataReply",
    "llVolumeDetect",
    "llGetRenderMaterial",
    "llGetRegionMoonDirection",
    "llLinkSitTarget",
    "llManageEstateAccess",
    "llToUpper",
    "llScriptProfiler",
    "llEmail",
    "llLookAt",
    "llJsonGetValue",
    "llRotBetween",
    "llGetNextEmail",
    "llLinksetDataRead",
    "llLinkParticleSystem",
    "llParcelMediaCommandList",
    "llCloseRemoteDataChannel",
    "llLog10",
    "llSetLinkRenderMaterial",
    "llGetSunDirection",
    "llGetRegionSunRotation",
    "llGetForce",
    "llScaleByFactor",
    "llExecCharacterCmd",
    "llGetBoundingBox",
    "llScaleTexture",
    "llSetAlpha",
    "llTextBox",
    "llGetMass",
    "llSetTexture",
    "llSin",
    "llGetParcelPrimCount",
    "llGetObjectMass",
    "llSetPrimitiveParams",
    "llGiveMoney",
    "llBreakLink",
    "llSitTarget",
    "llGround",
    "llDetectedPos",
    "llGetUnixTime",
    "llDetachFromAvatar",
    "llGetSunRotation",
    "llGetColor",
    "llMessageLinked",
    "llOpenRemoteDataChannel",
    "llGetPos",
    "llGetTextureRot",
    "llGetLocalPos",
    "llRot2Fwd",
    "llStartObjectAnimation",
    "llGetObjectLinkKey",
    "llGetRootRotation",
    "llList2CSV",
    "llAtan2",
    "llRemoveVehicleFlags",
    "llSetRegionPos",
    "llGetObjectAnimationNames",
    "llRezAtRoot",
    "llPointAt",
    "llModifyLand",
    "llListenRemove",
    "llGetObjectName",
    "llList2Rot",
    "llVecNorm",
    "llSound",
    "llDetectedVel",
    "llListen",
    "llAttachToAvatarTemp",
    "llInstantMessage",
    "llRotTarget",
    "llListenControl",
    "llGetPermissionsKey",
    "llGetEnv",
    "llResetOtherScript",
    "llLoopSoundSlave",
    "llOverMyLand",
    "llSetPos",
    "llGetTimestamp",
    "llGodLikeRezObject",
    "llGetMinScaleFactor",
    "llPlaySoundSlave",
    "llSetDamage",
    "llRemoteDataSetRegion",
    "llEuler2Rot",
    "llSetLinkTexture",
    "llDeleteKeyValue",
    "llGetAttachedList",
    "llGetLinkNumberOfSides",
    "llSetTouchText",
    "llXorBase64Strings",
    "llWhisper",
    "llGetRegionFPS",
    "llXorBase64",
    "llGroundRepel",
    "llListInsertList",
    "llGetMemoryLimit",
    "llGetScale",
    "llOpenFloater",
    "llGetDisplayName",
    "llGetNumberOfPrims",
    "llGetInventoryAcquireTime",
    "llSetForceAndTorque",
    "llGiveInventoryList",
    "llGetTorque",
    "llSetColor",
    "llCollisionSprite",
    "llAvatarOnLinkSitTarget",
    "llGetAgentInfo",
    "llRot2Angle",
    "llToLower",
    "llGetTextureScale",
    "llSetLinkPrimitiveParamsFast",
    "llRequestPermissions",
    "llGetGeometricCenter",
    "llResetLandPassList",
    "llSitOnLink",
    "llGetRegionName",
    "llSetVelocity",
    "llGetLinkPrimitiveParams",
    "llOffsetTexture",
    "llGetInventoryNumber",
    "llGetTimeOfDay",
    "llLinksetDataCountKeys",
    "llGetInventoryCreator",
    "llPatrolPoints",
    "llParcelMediaQuery",
    "llVecMag",
    "llSetVehicleFlags",
    "llSetLinkSitFlags",
    "llGetParcelPrimOwners",
    "llGetRegionSunDirection",
    "llLinkPlaySound",
    "llGetPrimMediaParams",
    "llGetLandOwnerAt",
    "llRequestURL",
    "llSHA1String",
    "llEdgeOfWorld",
    "llGetPhysicsMaterial",
    "llListReplaceList",
    "llGetCameraAspect",
    "llSetVehicleVectorParam",
    "llRequestExperiencePermissions",
    "llDetectedRot",
    "llGetHTTPHeader",
    "llGetParcelFlags",
    "llDetectedKey",
    "llList2Json",
    "llCastRay",
    "llSensorRepeat",
    "llGetCenterOfMass",
    "llPushObject",
    "llGetVisualParams",
    "llIsFriend",
    "llClearPrimMedia",
    "llGetAnimationList",
    "llDamage",
    "llDetectedRezzer",
}


def _any_arg_list(func: LSLFunction) -> bool:
    return any(a.type == LSLType.LIST for a in func.arguments)


def _any_list(func: LSLFunction) -> bool:
    return func.ret_type == LSLType.LIST or _any_arg_list(func)


def gen_mono_library_defs(
    definitions: LSLDefinitions, library_template_path: str, output_path: str
) -> None:
    """
    Generate CSharp binding code for LslLibrary.cs

    Example:
    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    public extern static void llAdjustDamage(int Number, float Damage);
    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    public extern static object[] llDetectedDamageInternal(int Number);

    public static ArrayList llDetectedDamage(int Number) {
        return ToArrayListNoCopy(llDetectedDamageInternal(Number));
    }
    """
    with open(library_template_path, "r") as f:
        template = f.read()

    new_defs = ""
    for func in definitions.functions.values():
        if func.name in _OLD_FUNC_BLACKLIST:
            continue
        new_defs += "        [MethodImplAttribute(MethodImplOptions.InternalCall)]\n"
        if _any_list(func):
            # If the function does anything with lists we need special wrapper code
            # Write the internal implementation
            ret_str = "object[]" if func.ret_type == LSLType.LIST else func.ret_type.meta.cs_name

            args_strs = []
            for arg in func.arguments:
                if arg.type == LSLType.LIST:
                    args_strs.append(f"object[] {arg.name}")
                    args_strs.append(f"int {arg.name}_len")
                else:
                    args_strs.append(f"{arg.type.meta.cs_name} {arg.name}")

            args_str = ", ".join(args_strs)
            new_defs += (
                f"        public extern static {ret_str} {func.name}Internal({args_str});\n\n"
            )

            # Now for the wrapper implementation
            args_str = ", ".join(f"{a.type.meta.cs_name} {a.name}" for a in func.arguments)
            new_defs += (
                f"        public static {func.ret_type.meta.cs_name} {func.name}({args_str}) {{\n"
            )

            call_args = []
            for arg in func.arguments:
                if arg.type == LSLType.LIST:
                    call_args.append(f"ToArrayNoCopy({arg.name})")
                    call_args.append(f"{arg.name}.Count")
                else:
                    call_args.append(arg.name)

            call_expr = f"{func.name}Internal({', '.join(call_args)})"
            if func.ret_type == LSLType.LIST:
                # List returns don't have a length component like list args, the embedding
                # code must infer the length through Mono APIs.
                call_expr = f"ToArrayListNoCopy({call_expr})"
            if func.ret_type == LSLType.VOID:
                # Mono very much dislikes using a return from an otherwise void function
                new_defs += f"            {call_expr};\n"
            else:
                new_defs += f"            return {call_expr};\n"
            new_defs += "        }\n\n"
        else:
            args_str = ", ".join(f"{a.type.meta.cs_name} {a.name}" for a in func.arguments)
            new_defs += f"        public extern static {func.ret_type.meta.cs_name} {func.name}({args_str});\n"

    formatted = _splice(template, _MONO_CS_LIBRARY_DEFS_COMMENT, new_defs)
    _write_if_different(output_path, formatted)


def _func_name_to_impl_name(name: str) -> str:
    """
    Converts llHTTPRequestXYZ to http_request_xyz_func

    This is the expected form for LSL func implementations
    """
    assert name.startswith("ll")
    name = name[2:]

    # Foo2Bar -> FooToBar and FOO2Bar -> FOOToBar, where applicable
    name = re.sub(r"(?<=[a-zA-Z])2(?=[A-Z])", "To", name)

    # Base64ToString -> base64_to_string
    # HTTPRequest -> http_request
    pattern = re.compile(r"(?<=[a-z0-9])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])")
    return pattern.sub("_", name).lower() + "_func"


def gen_mono_bind_interfaces(definitions: LSLDefinitions, mono_bind_interfaces_path: str) -> None:
    """
    Generate bindings so Mono functions can call the underlying functions from gScriptLibrary

    Example:

    static void _mono_binding_wander_within_func(MonoVectorType p0, MonoVectorType p1, MonoListType p2, S32 p2_length)
    {
        LLScriptLibData args[3];
        LLScriptLibDataHelper<MonoVectorType>::set(args[0], p0);
        LLScriptLibDataHelper<MonoVectorType>::set(args[1], p1);
        LLScriptLibDataHelper<MonoListType>::set(args[2], p2, p2_length);
        LLScriptLibData retval;
        retval.mType = LST_NULL;
        // Where 401 is the function ID and 10.0 and 0.0 are the energy and sleep for the function
        // Using the function ID is ideal because it allows us to avoid binding to a specific implementation
        // of a function if we want to mock in our tests.
        call_lib_func(401, retval, args, 10.0, 0.0);
        return LLScriptLibDataHelper<void>::get(retval);
    }

    ...

    void mono_internal_call_init_generated()
    {
    // ...
        mono_add_internal_call("LindenLab.SecondLife.Library::llWanderWithinInternal", fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_wander_within_func)));
    // ...
    }
    """
    binding_calls = ""
    functions = ""
    for func in definitions.functions.values():
        if func.native:
            # Naturally, we don't need to bind native functions. They're native!
            continue

        # Bind to Mono VM
        # We use "Internal" as a suffix if either a retval or arg is a list
        # because there should be a C# wrapper deal with array<->ArrayList conversion.
        mono_func_name = f"{func.name}Internal" if _any_list(func) else func.name
        impl_name = _func_name_to_impl_name(func.name)

        arg_spec = []
        function_stmts = [
            f"LLScriptLibData args[{len(func.arguments)}];",
        ]
        for i, arg in enumerate(func.arguments):
            arg_bind_name = arg.type.meta.mono_bind_name
            arg_spec.append(f"{arg_bind_name} p{i}")
            if arg.type == LSLType.LIST:
                # Lists have both the array _and a length_ when passed as args
                arg_spec.append(f"S32 p{i}_length")
                function_stmts.append(
                    f"LLScriptLibDataHelper<{arg_bind_name}>::set(args[{i}], p{i}, p{i}_length);"
                )
            else:
                function_stmts.append(
                    f"LLScriptLibDataHelper<{arg_bind_name}>::set(args[{i}], p{i});"
                )

        ret_bind_name = func.ret_type.meta.mono_bind_name
        function_stmts.extend(
            [
                "LLScriptLibData retval;",
                f"retval.mType = {func.ret_type.meta.lst_name};",
                f"call_lib_func({func.func_id}, retval, {len(func.arguments)}, args, {func.energy}, {func.mono_sleep});",
                f"return LLScriptLibDataHelper<{ret_bind_name}>::get(retval);",
            ]
        )
        function_stmts_str = "\n    ".join(function_stmts)

        functions += f"static {ret_bind_name} _mono_binding_{impl_name}({', '.join(arg_spec)})\n{{\n    {function_stmts_str}\n}}\n\n"

        binding_calls += (
            f'    mono_add_internal_call("LindenLab.SecondLife.Library::{mono_func_name}",'
            f" fnPtrToObjPtr(reinterpret_cast<PtrType>(_mono_binding_{impl_name})));\n"
        )

    binding_file_code = """
extern "C"
{
#include <mono/metadata/metadata.h>
#include <mono/metadata/object.h>
#include <mono/jit/jit.h>
}

#include "llscriptexecutemono.h"
#include "llmonointerfacehelpers.h"

typedef void (*PtrType)();

%s

void mono_internal_call_init_generated()
{
%s
}
""" % (functions, binding_calls)
    _write_if_different(mono_bind_interfaces_path, binding_file_code)


def gen_lscript_interface(definitions: LSLDefinitions, lscript_interface_path: str) -> None:
    """
    Generate binding code to include in lscript_interface.cpp

    void task_lscript_init_generated()
    {
        gScriptLibrary.assignExec("llAxisAngle2Rot", axis_angle_to_rot_func);
        gScriptLibrary.assignExec("llListSortStrided", list_sort_strided_func);
        // ...
    }
    """
    assign_execs = ""
    for func in definitions.functions.values():
        impl_name = _func_name_to_impl_name(func.name)
        if func.name in _OLD_FUNC_BLACKLIST:
            continue
        # Meh. If this is an older function it should be explicitly bound by `gScriptLibrary.assignExec()`.
        # Bind to LSO VM
        assign_execs += f'    gScriptLibrary.assignExec("{func.name}", {impl_name});\n'

    function_code = (
        """
void task_lscript_init_generated()
{
%s
}
"""
        % assign_execs
    )
    _write_if_different(lscript_interface_path, function_code)


def gen_builtins_txt(definitions: LSLDefinitions, output_path: str) -> None:
    """Generate a builtins.txt for LSLint-compatible implementations"""
    # See https://github.com/Sei-Lisa/kwdb/blob/master/outputs/builtins.txt for an example
    builtins_str = "// Generated by gen_definitions.py\n"

    for func in sorted(definitions.functions.values(), key=lambda x: x.name):
        args_str = ", ".join(f"{x.type!s} {x.name}" for x in func.arguments)
        builtins_str += f"{func.ret_type!s} {func.name}( {args_str} )\n"

    for const in sorted(definitions.constants.values(), key=lambda x: x.name):
        builtins_str += f"const {const.type!s} {const.name} = "
        if const.type == LSLType.STRING:
            # We don't use C encoding semantics to escape values because LSL only knows
            # about a handful of basic escapes like `\n`.
            # Other values we want to output verbatim.
            lsl_val = const.value.replace("\\", "\\\\").replace("\n", "\\n")
            builtins_str += f'"{lsl_val}"'
        else:
            builtins_str += const.value
        builtins_str += "\n"

    for event in sorted(definitions.events.values(), key=lambda x: x.name):
        args_str = ", ".join(f"{x.type!s} {x.name}" for x in event.arguments)
        builtins_str += f"event {event.name}( {args_str} )\n"

    _write_if_different(output_path, builtins_str)


def gen_lua_registrations(definitions: LSLDefinitions, pure_only: bool, output_path: str) -> None:
    """Generate lambdas to handle incoming Lua calls that wrap ll*() lscript functions"""
    bindings = []
    for func in definitions.functions.values():
        if not func.pure and pure_only:
            continue
        # `ll` prefix is superfluous for namespacing functions, this is all going to live
        # in the `ll` module.
        assert func.name.startswith("ll")
        func_name = func.name[2:]

        binding = """
{"%(func_name)s", [](lua_State *L) {
    LLScriptLibData args[%(num_args)d];
    const LSCRIPTType types[] = {%(arg_types)s};
    // Convert the arguments to LLScriptLibData, throwing if not possible.
    extract_lua_args(L, %(num_args)d, types, args);
    return call_lib_func_lua(L, %(func_id)d, %(num_args)d, args, %(ret_type)s);
}}
        """ % {
            "num_args": len(func.arguments),
            "ret_type": func.ret_type.meta.lst_name,
            "arg_types": ", ".join(a.type.meta.lst_name for a in func.arguments),
            "func_id": func.func_id,
            "func_name": func_name,
        }
        bindings.append(binding)
    _write_if_different(output_path, ",".join(bindings))


def _is_uuid(val: str) -> bool:
    return bool(re.match(r"\A[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}\Z", val))


def gen_lua_constant_definitions(definitions: LSLDefinitions, output_path: str) -> None:
    """Generate lambdas to handle incoming Lua calls that wrap ll*() lscript functions"""
    # TODO: This would be much better as a constant folding pass in the compiler.
    #  there are a ton of constants and putting them all in the runtime environment
    #  is not free.
    bindings = []
    for const in definitions.constants.values():
        binding = "    "
        if const.type == LSLType.KEY or _is_uuid(const.value):
            # This is a bit weird. UUID constants don't exist in LSL, but they do in Lua.
            # Make these an actual UUID if we can to make comparison easier.
            binding += f'luaSL_pushuuidstring(L, "{_to_c_str(const.value)}");'
        elif const.type == LSLType.STRING:
            binding += f'lua_pushstring(L, "{_to_c_str(const.value)}");'
        elif const.type == LSLType.INTEGER:
            binding += f"luaSL_pushnativeinteger(L, {const.value});"
        elif const.type == LSLType.FLOAT:
            binding += f"lua_pushnumber(L, {const.value});"
        elif const.type == LSLType.VECTOR:
            binding += f"lua_pushvector(L, {const.value[1:-1]});"
        elif const.type == LSLType.ROTATION:
            binding += f"luaSL_pushquaternion(L, {const.value[1:-1]});"
        else:
            raise ValueError(f"Can't generate Lua constant for {const.name} of type {const.type}")

        binding += f'\n    lua_setglobal(L, "{_to_c_str(const.name)}");\n'
        bindings.append(binding)
    _write_if_different(output_path, "\n".join(bindings))


def gen_lscript_library_bind_pure(definitions: LSLDefinitions, output_path: str) -> None:
    """
    Bind lscript functions for all pure functions, useful for test harnesses

    Used by `bind_pure_lscript_functions(LLScriptLibrary& library)`.
    """

    assign_execs = ""
    for func in definitions.functions.values():
        if not func.pure:
            continue

        impl_name = _func_name_to_impl_name(func.name)
        assign_execs += f'    library.assignExec("{func.name}", {impl_name});\n'
    _write_if_different(output_path, "".join(assign_execs))


def main():
    argparser = argparse.ArgumentParser(description="Process LSL definitions.")
    argparser.add_argument("definitions", help="Path to the LSL definition yaml")

    subparsers = argparser.add_subparsers(dest="mode", required=True)

    sub = subparsers.add_parser("syntax")
    sub.add_argument("filename")
    sub.set_defaults(func=lambda args, defs: _write_if_different(args.filename, dump_syntax(defs)))

    sub = subparsers.add_parser("gen_constant_lsl_script")
    sub.set_defaults(func=lambda args, defs: gen_constant_lsl_script(defs))

    sub = subparsers.add_parser("gen_lexer_file")
    sub.add_argument("template_file")
    sub.add_argument("output_file")
    sub.set_defaults(
        func=lambda args, defs: gen_lexer_file(defs, args.template_file, args.output_file)
    )

    sub = subparsers.add_parser("gen_parser_file")
    sub.add_argument("template_file")
    sub.add_argument("output_file")
    sub.set_defaults(
        func=lambda args, defs: gen_parser_file(defs, args.template_file, args.output_file)
    )

    sub = subparsers.add_parser("gen_tree_header_file")
    sub.add_argument("output_file")
    sub.set_defaults(func=lambda args, defs: gen_tree_header_file(defs, args.output_file))

    sub = subparsers.add_parser("gen_tree_source_file")
    sub.add_argument("output_file")
    sub.set_defaults(func=lambda args, defs: gen_tree_source_file(defs, args.output_file))

    sub = subparsers.add_parser("gen_cpp_constants")
    sub.add_argument("output_file")
    sub.set_defaults(func=lambda args, defs: gen_cpp_constants(defs, args.output_file))

    sub = subparsers.add_parser("gen_func_call_scripts")
    sub.add_argument("output_path")
    sub.set_defaults(func=lambda args, defs: gen_func_call_scripts(defs, args.output_path))

    sub = subparsers.add_parser("gen_lscript_library_defs")
    sub.add_argument("library_path")
    sub.set_defaults(func=lambda args, defs: gen_lscript_library_defs(defs, args.library_path))

    sub = subparsers.add_parser("gen_mono_library_defs")
    sub.add_argument("library_template_path")
    sub.add_argument("output_file")
    sub.set_defaults(
        func=lambda args, defs: gen_mono_library_defs(
            defs, args.library_template_path, args.output_file
        )
    )

    sub = subparsers.add_parser("gen_lscript_interface")
    sub.add_argument("lscript_interface_path")
    sub.set_defaults(
        func=lambda args, defs: gen_lscript_interface(defs, args.lscript_interface_path)
    )

    sub = subparsers.add_parser("gen_mono_bind_interfaces")
    sub.add_argument("mono_bind_interfaces_path")
    sub.set_defaults(
        func=lambda args, defs: gen_mono_bind_interfaces(defs, args.mono_bind_interfaces_path)
    )

    sub = subparsers.add_parser("gen_lscript_library_bind_pure")
    sub.add_argument("output_path")
    sub.set_defaults(func=lambda args, defs: gen_lscript_library_bind_pure(defs, args.output_path))

    sub = subparsers.add_parser("gen_builtins_txt")
    sub.add_argument("output_path")
    sub.set_defaults(func=lambda args, defs: gen_builtins_txt(defs, args.output_path))

    sub = subparsers.add_parser("gen_lua_registrations")
    sub.add_argument("pure_only", type=int, help="0 or 1")
    sub.add_argument("output_path")
    sub.set_defaults(
        func=lambda args, defs: gen_lua_registrations(defs, bool(args.pure_only), args.output_path)
    )

    sub = subparsers.add_parser("gen_lua_constant_definitions")
    sub.add_argument("output_path")
    sub.set_defaults(func=lambda args, defs: gen_lua_constant_definitions(defs, args.output_path))

    args = argparser.parse_args()

    parser = LSLDefinitionParser()
    definitions = parser.parse_file(args.definitions)

    args.func(args, definitions)


if __name__ == "__main__":
    main()
