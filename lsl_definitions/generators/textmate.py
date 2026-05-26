from __future__ import annotations

import json
import os
import re
from dataclasses import dataclass
from string import Template

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions
from lsl_definitions.slua import SLuaDefinitions, SLuaModule, SLuaProperty


@dataclass
class Trie:
    value: str = ""
    child: Trie | None = None
    next: Trie | None = None
    count: int = 0

    def add(self, s: str) -> None:
        if s == "":
            self.count += 1
            return
        elif s[0] == self.value:
            if self.child is None:
                self.child = Trie()
            return self.child.add(s[1:])
        elif self.next is None:
            self.next = Trie(value=s[0])
        elif s[0] < self.next.value:
            self.next = Trie(value=s[0], next=self.next)
        return self.next.add(s)

    def _patterns(self, patterns: list[str]) -> list[str]:
        """Iterate one level of the trie"""
        if self.count:
            patterns.append("")
        if self.child:
            patterns.append(re.escape(self.value) + self.child.pattern())
        if self.next:
            return self.next._patterns(patterns)
        else:
            return patterns

    def pattern(self) -> str:
        patterns = self._patterns([])
        if len(patterns) == 0:
            raise ValueError("no entries")
        elif len(patterns) == 1:
            return patterns[0]
        # elif patterns[0] == "":
        #     return f"(?:{'|'.join(patterns[1:])})?"
        else:
            return f"(?:{'|'.join(patterns)})"


## End of Trie Code


def encode_json_unquoted(s):
    return json.dumps(s)[1:-1]


def crunch_regex_strings(strings: list[str]) -> str:
    trie = Trie()
    strings.sort()
    for string in strings:
        trie.add(string)
    return trie.pattern()


@register("syntax_textmate_slua")
def gen_textmate_slua(
    definitions: LSLDefinitions, template_path: str, slua_definitions: SLuaDefinitions
) -> str:
    """Generate SLua TextMate Syntax Files."""

    quaternion_module = slua_definitions.get_module("quaternion")
    rotation_module = SLuaModule(
        name="rotation",
        comment=quaternion_module.comment,
        callable=quaternion_module.callable,
        constants=quaternion_module.constants,
        functions=quaternion_module.functions,
    )
    slua_definitions.modules.append(rotation_module)

    def get_slua_global_functions(definitions: SLuaDefinitions) -> str:
        functions = [
            f.name for f in definitions.functions if not f.local_only and not f.slua_removed
        ]
        functions += [m.name for m in definitions.modules if m.callable is not None]
        functions.sort()
        return "|".join(functions)

    def get_slua_global_constants_for_module(module: SLuaModule) -> str:
        constants = [c.name for c in module.constants if not c.private]
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
        functions = [f.name for f in module.functions if not f.private and not f.local_only]
        functions.sort()
        functions = "|".join(functions)
        if len(functions) < 1:
            return None
        return f"{module.name}\\.(?:{functions})"

    def get_LL_constants(slua_definitions: SLuaDefinitions) -> str:
        constants = [c.name for c in slua_definitions.global_constants]
        return crunch_regex_strings(constants)

    def get_slua_modules(definitions: SLuaDefinitions) -> str:
        modules = [get_slua_module_regex(m) for m in definitions.modules]
        modules = [m for m in modules if m is not None]
        modules.sort()
        return "|".join(modules)

    def get_LL_module_functions(definitions: SLuaDefinitions) -> str:
        functions = [
            f.name
            for f in definitions.get_module("ll").functions
            if not f.private and not f.local_only and not f.slua_removed and f.deprecated is None
        ]
        return crunch_regex_strings(functions)

    def get_LL_module_deprecated_functions(definitions: SLuaDefinitions) -> str:
        functions = [
            f.name
            for f in definitions.get_module("ll").functions
            if not f.private
            and not f.local_only
            and not f.slua_removed
            and f.deprecated is not None
        ]
        return crunch_regex_strings(functions)

    def get_slua_global_types(definitions: SLuaDefinitions) -> str:
        # Missing types that are not documented in builtins, classes or aliases
        missing_types = ["nil"]
        builtin_types = [t for t in definitions.builtin_types.keys()]
        base_classes = [b.name for b in definitions.base_classes]
        type_aliases = [t.name for t in definitions.type_aliases if t.export]
        return "|".join(missing_types + builtin_types + base_classes + type_aliases)

    def get_slua_metamethods(definitions: SLuaDefinitions) -> str:
        metamethods = [f"{m[2:]}" for m in definitions.metamethods.keys()]
        metamethods = "|".join(metamethods)
        return f"__(?:{metamethods})"

    def get_LL_variable_functions_for_variable(
        variable: SLuaProperty, definitions: SLuaDefinitions
    ) -> str:
        clss = definitions.get_class(variable.type)
        if clss is None:
            return []
        return [
            f"{variable.name}:{m.name}" for m in clss.methods if not m.private and not m.local_only
        ]

    def get_LL_variable_functions(definitions: SLuaDefinitions) -> str:
        functions = []
        for v in definitions.global_variables:
            functions.extend(get_LL_variable_functions_for_variable(v, slua_definitions))
        functions.sort()
        return crunch_regex_strings(functions)

    def get_LL_variables_for_variable(variable: SLuaProperty, definitions: SLuaDefinitions) -> str:
        clss = definitions.get_class(variable.type)
        if clss is None:
            return []
        return [f"{variable.name}.{p.name}" for p in clss.properties if not p.private]

    def get_LL_variables(definitions: SLuaDefinitions) -> str:
        variables = []
        for v in definitions.global_variables:
            variables.extend(get_LL_variables_for_variable(v, definitions))
        variables.sort()
        return crunch_regex_strings(variables)

    inserts = dict(
        SLUA_GLOBAL_FUNCTIONS_REGEX=get_slua_global_functions(slua_definitions),
        SLUA_GLOBAL_MODULES_REGEX=get_slua_modules(slua_definitions),
        SLUA_GLOBAL_CONSTANTS_REGEX=get_slua_global_constants(slua_definitions),
        SLUA_GLOBAL_LSL_CONSTANTS_REGEX=get_LL_constants(slua_definitions),
        SLUA_GLOBAL_LL_MODULE_REGEX=get_LL_module_functions(slua_definitions),
        SLUA_GLOBAL_LL_MODULE_DEPRECATED_REGEX=get_LL_module_deprecated_functions(slua_definitions),
        # nil|string|number|boolean|thread|userdata|symbol|vector|buffer|unknown|never|any
        SLUA_GLOBAL_TYPES_REGEX=get_slua_global_types(slua_definitions),
        SLUA_METAMETHODS_REGEX=get_slua_metamethods(slua_definitions),
        SLUA_GLOBAL_LL_VARIABLE_FUNCTIONS_REGEX=get_LL_variable_functions(slua_definitions),
        SLUA_GLOBAL_LL_VARIABLES_REGEX=get_LL_variables(slua_definitions),
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
        LSL_FLOW_CONTROL_REGEX=crunch_regex_strings(list(definitions.controls.keys())),
        LSL_TYPES_REGEX=crunch_regex_strings(list(definitions.types.keys())),
        LSL_EVENTS_REGEX=crunch_regex_strings(list(definitions.events.keys())),
        LSL_FUNCTIONS_REGEX=crunch_regex_strings(
            [
                name
                for name, func in definitions.functions.items()
                if not func.private and not func.deprecated and not func.god_mode
            ]
        ),
        LSL_FUNCTIONS_GOD_MODE_REGEX=crunch_regex_strings(
            [name for name, func in definitions.functions.items() if func.god_mode]
        ),
        LSL_FUNCTIONS_DEPRECATED_REGEX=crunch_regex_strings(
            [name for name, func in definitions.functions.items() if func.deprecated]
        ),
        LSL_FUNCTIONS_ILLEGAL_REGEX=crunch_regex_strings(
            [name for name, func in definitions.functions.items() if func.private]
        ),
        LSL_FUNCTION_CONSTANTS_REGEX=crunch_regex_strings(
            [
                name
                for name, const in definitions.constants.items()
                if not const.private and not const.deprecated
            ]
        ),
        LSL_CONSTANTS_DEPRECATED_REGEX=crunch_regex_strings(
            [
                name
                for name, const in definitions.constants.items()
                if not const.private and const.deprecated
            ]
        ),
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
