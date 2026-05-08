from __future__ import annotations
from asyncio import constants

from lsl_definitions.lsl import LSLDefinitions, LSLType
from lsl_definitions.slua import SLuaDefinitions, SLuaModule
from lsl_definitions.generators.base import register

from string import Template

import os
import json
import re


class Trie():
    """Regex::Trie in Python. Creates a Trie out of a list of words. The trie can be exported to a Regex pattern.
    The corresponding Regex should match much faster than a simple Regex union."""

    def __init__(self):
        self.data = {}

    def add(self, word):
        ref = self.data
        for char in word:
            ref[char] = char in ref and ref[char] or {}
            ref = ref[char]
        ref[''] = 1

    def dump(self):
        return self.data

    def quote(self, char):
        return re.escape(char)

    def _pattern(self, pData):
        data = pData
        if "" in data and len(data.keys()) == 1:
            return None

        alt = []
        cc = []
        q = 0
        for char in sorted(data.keys()):
            if isinstance(data[char], dict):
                try:
                    recurse = self._pattern(data[char])
                    alt.append(self.quote(char) + recurse)
                except:
                    cc.append(self.quote(char))
            else:
                q = 1
        cconly = not len(alt) > 0

        if len(cc) > 0:
            if len(cc) == 1:
                alt.append(cc[0])
            else:
                alt.append('[' + ''.join(cc) + ']')

        if len(alt) == 1:
            result = alt[0]
        else:
            result = "(?:" + "|".join(alt) + ")"

        if q:
            if cconly:
                result += "?"
            else:
                result = "(?:%s)?" % result
        return result

    def pattern(self):
        return self._pattern(self.dump())

def encode_json_unquoted(s):
    return json.dumps(s)[1:-1]

def get_LSL_constants(definitions: LSLDefinitions, slua: bool = False) -> dict:
    constants = [f"{c.name}" for c in definitions.constants.values() if (slua and not c.slua_removed) or (not slua)]
    return crunch_regex_strings(constants)

def crunch_regex_strings(strings: list[str]) -> str:
    trie = Trie()
    strings.sort()
    for string in strings:
        trie.add(string)
    return trie.pattern()

@register("syntax_textmate_slua")
def gen_textmate_slua(definitions: LSLDefinitions, template_path: str, slua_definitions: SLuaDefinitions) -> str:
    """Generate SLua TextMate Syntax Files."""

    def get_LL_module_functions(definitions: LSLDefinitions) -> dict:
        functions = [f"{f.name[2:]}" for f in definitions.functions.values() if not f.slua_removed and not f.private and not f.deprecated]
        return crunch_regex_strings(functions)

    def get_slua_global_functions(definitions: SLuaDefinitions) -> dict:
        global_functions = [f"{f.name}" for f in definitions.global_functions if not f.local_only and not f.slua_removed]
        builtin_functions = [f"{f.name}" for f in definitions.builtin_functions if not f.local_only and not f.slua_removed]
        callable_tables = [f"{m.name}" for m in definitions.modules if m.callable is not None]
        functions = global_functions + builtin_functions + callable_tables
        functions.sort()
        return "|".join(functions)

    def get_slua_global_constants_for_module(module: SLuaModule) -> str:
        constants = [f"{c.name}" for c in module.constants if not c.private]
        constants.sort()
        constants = "|".join(constants)
        if len(constants) > 0:
            constants = f"(\\.{constants})?"
        return f"{module.name}{constants}"

    def get_slua_global_constants(definitions: SLuaDefinitions) -> str:
        constants = [get_slua_global_constants_for_module(m) for m in definitions.modules]
        constants.sort()
        return "|".join(constants)

    def get_slua_module_regex(module: SLuaModule) -> str:
        if module.name in {"ll", "llcompat"}:
            return None
        functions = [f"{f.name}" for f in module.functions if not f.private and not f.local_only]
        functions.sort()
        functions = "|".join(functions)
        if len(functions) < 1:
            return None
        return f"{module.name}\\.(?:{functions})"

    def get_slua_modules(definitions: SLuaDefinitions) -> str:
        modules = [get_slua_module_regex(m) for m in definitions.modules]
        modules = [m for m in modules if m is not None]
        modules.sort()
        return "|".join(modules)


    inserts = dict(
        SLUA_GLOBAL_FUNCTIONS_REGEX=get_slua_global_functions(slua_definitions),
        SLUA_GLOBAL_MODULES_REGEX=get_slua_modules(slua_definitions),
        SLUA_GLOBAL_CONSTANTS_REGEX=get_slua_global_constants(slua_definitions),
        SLUA_GLOBAL_LSL_CONSTANTS_REGEX=get_LSL_constants(definitions, slua=True),
        SLUA_GLOBAL_LL_MODULE_REGEX=get_LL_module_functions(definitions),
    )

    _base, ext = os.path.splitext(template_path)

    with open(template_path, "r") as f:
        template = Template(f.read())
        if ext == ".tmLanguage":
            return template.safe_substitute(inserts)
        elif ext == ".json":
            inserts = {k: encode_json_unquoted(v) for k, v in inserts.items()}
            return template.safe_substitute(inserts)
        else:
            raise ValueError(f"Unsupported template extension: {ext}")

@register("syntax_textmate_lsl")
def gen_textmate_lsl(definitions: LSLDefinitions, template_path: str) -> str:

    inserts = dict(
        LSL_FLOW_CONTROL_REGEX=crunch_regex_strings(["default", "event","print"] + [c for c in definitions.controls.keys()]),
        LSL_TYPES_REGEX=crunch_regex_strings([t for t in definitions.types.keys()]),
        LSL_EVENTS_REGEX=crunch_regex_strings([e for e in definitions.events.keys()]),

        LSL_FUNCTIONS_REGEX=crunch_regex_strings([f"{name}" for name, func in definitions.functions.items() if not func.private and not func.deprecated and not func.god_mode]),
        LSL_FUNCTIONS_GOD_MODE_REGEX=crunch_regex_strings([f"{name}" for name, func in definitions.functions.items() if func.god_mode]),
        LSL_FUNCTIONS_DEPRECATED_REGEX=crunch_regex_strings([f"{name}" for name, func in definitions.functions.items() if func.deprecated]),
        LSL_FUNCTIONS_ILLEGAL_REGEX=crunch_regex_strings([f"{name}" for name, func in definitions.functions.items() if func.private]),

        LSL_FUNCTION_CONSTANTS_REGEX=crunch_regex_strings([f"{name}" for name, const in definitions.constants.items() if not const.private and not const.deprecated]),
        LSL_CONSTANTS_DEPRECATED_REGEX=crunch_regex_strings([f"{name}" for name, const in definitions.constants.items() if not const.private and const.deprecated]),
    )

    _base, ext = os.path.splitext(template_path)

    with open(template_path, "r") as f:
        template = Template(f.read())
        if ext == ".tmLanguage":
            return template.safe_substitute(inserts)
        elif ext == ".json":
            inserts = {k: encode_json_unquoted(v) for k, v in inserts.items()}
            return template.safe_substitute(inserts)
        else:
            raise ValueError(f"Unsupported template extension: {ext}")