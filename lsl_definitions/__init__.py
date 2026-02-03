"""LSL (Linden Scripting Language) definitions package."""

import uuid

import yaml

from lsl_definitions.lsl import (
    LSLArgument,
    LSLConstant,
    LSLDefinitionParser,
    LSLDefinitions,
    LSLEvent,
    LSLFunction,
    LSLFunctionRanges,
    LSLType,
    LSLTypeMeta,
)
from lsl_definitions.slua import (
    SLuaClassDeclaration,
    SLuaDefinitionParser,
    SLuaDefinitions,
    SLuaFunction,
    SLuaFunctionBase,
    SLuaFunctionOverload,
    SLuaModule,
    SLuaParameter,
    SLuaProperty,
    SLuaTypeAlias,
)


def quoted_presenter(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style='"')


yaml.add_representer(uuid.UUID, quoted_presenter)


__all__ = [
    # LSL
    "LSLArgument",
    "LSLConstant",
    "LSLDefinitionParser",
    "LSLDefinitions",
    "LSLEvent",
    "LSLFunction",
    "LSLFunctionRanges",
    "LSLType",
    "LSLTypeMeta",
    # SLua
    "SLuaClassDeclaration",
    "SLuaDefinitionParser",
    "SLuaDefinitions",
    "SLuaFunction",
    "SLuaFunctionBase",
    "SLuaFunctionOverload",
    "SLuaModule",
    "SLuaParameter",
    "SLuaProperty",
    "SLuaTypeAlias",
]
