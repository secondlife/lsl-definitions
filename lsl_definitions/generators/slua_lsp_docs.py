"""Generator for SLua documentation files for Luau LSP, like this one:
https://github.com/MaximumADHD/Roblox-Client-Tracker/blob/roblox/api-docs/en-us.json
"""

from __future__ import annotations

import dataclasses
import json

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions
from lsl_definitions.slua import (
    SLuaDefinitions,
    SLuaFunction,
    SLuaModule,
    SLuaProperty,
)
from lsl_definitions.utils import (
    remove_nones,
)

GLOBALS_PREFIX = "@sl-slua/global/"


def htmlize(text: str) -> str:
    text = text.replace("\\n", "\n").strip()
    text = text.replace("\n", "<br>")
    text = text.replace("    ", "&nbsp;&nbsp;")
    text = text.replace("\t", "&nbsp;")
    return text


def doc_url(module: str | None, func: str | None) -> str | None:
    # TODO: None of these links actually exist
    if module in {"ll", "llcompat"} and func is not None:
        return f"https://wiki.secondlife.com/wiki/Ll{func}"
    if func in {"toquaternion", "tovector"}:
        return f"https://create.secondlife.com/script/slua-reference/{func}/"
    if module in {"uuid", "vector", "quaternion", "bit32", "lljson", "llbase64"}:
        if func is None:
            return f"https://create.secondlife.com/script/slua-reference/{module}/"
    return None


@dataclasses.dataclass
class DocBuilder:
    docs: dict = dataclasses.field(default_factory=dict)

    def add_function(self, func: SLuaFunction, module: str | None = None, method=False):
        module_prefix = f"{module}." if module else ""
        entry = remove_nones(
            documentation=htmlize(func.comment or f"{func.name} function"),
            learn_more_link=doc_url(module, func.name),
        )
        self.docs[f"{GLOBALS_PREFIX}{module_prefix}{func.name}"] = entry

    def add_constant(self, const: SLuaProperty, module: str | None = None):
        module_prefix = f"{module}." if module else ""
        value = f"Value: {const.value}" if const.value is not None else ""
        comment = htmlize(const.comment)
        documentation = value + "<br>" + comment if comment and value else value + comment
        entry = remove_nones(
            documentation=documentation,
            learn_more_link=doc_url(module, const.name),
        )
        self.docs[f"{GLOBALS_PREFIX}{module_prefix}{const.name}"] = entry

    def add_module(self, module: SLuaModule) -> None:
        if module.callable:
            self.add_function(module.callable)
        else:
            self.docs[f"{GLOBALS_PREFIX}{module.name}"] = remove_nones(
                documentation=htmlize(module.comment),
                learn_more_link=doc_url(module.name, None),
            )
        # for const in sorted(self.constants, key=lambda x: x.name)
        for const in module.constants:
            if not const.private:
                self.add_constant(const, module=module.name)
        # for func in sorted(self.functions, key=lambda x: x.name)
        for func in module.functions:
            if not func.private:
                self.add_function(func, module=module.name)


@register("slua_lsp_docs")
def gen_slua_lsp_docs(definitions: LSLDefinitions, slua_definitions: SLuaDefinitions) -> str:
    """Generate SLua standard library for Luau LSP docs.json"""
    slua_definitions.generate_ll_modules(definitions)
    builder = DocBuilder()

    # Duplicate quaternion module as rotation. The callable aspect of quaternion
    # prevents us from being able to de-duplicate this with structs.
    modules = {m.name: m for m in slua_definitions.modules}
    modules["rotation"] = SLuaModule(
        name="rotation",
        comment=modules["quaternion"].comment,
        callable=modules["quaternion"].callable,
        constants=modules["quaternion"].constants,
        functions=modules["quaternion"].functions,
    )

    # class docs are unused if generated
    #     for const in slua_definitions.globalVariables:
    #         if not const.private and const.name != "rotation":
    #             selene["globals"][const.name] = selene_property(const)
    # builtin docs are unused if generated
    # for func in slua_definitions.builtinFunctions:
    #     builder.add_function(func)
    for func in slua_definitions.globalFunctions:
        builder.add_function(func)
    for module in sorted(modules.values(), key=lambda x: x.name):
        if module.name not in {"ll", "llcompat"}:
            builder.add_module(module)
    builder.add_module(modules["ll"])
    builder.add_module(modules["llcompat"])
    # builtin docs are unused if generated
    # for const in slua_definitions.builtinConstants:
    #     builder.add_constant(const)
    for const in sorted(slua_definitions.globalConstants, key=lambda x: x.name):
        if not const.private and not const.slua_removed:
            builder.add_constant(const)
    # class docs are unused if generated
    #     for class_ in classes.values():
    #         selene["structs"][class_.name] = selene_class(class_)

    return json.dumps(builder.docs, indent=4)
