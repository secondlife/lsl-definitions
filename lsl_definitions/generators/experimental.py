"""
Generators to explore internal structures that aren't exposed by other generators.
Primarily for debugging the documentation-only structures,
as document generators do not live in this repositary, but do use this data.
"""

from __future__ import annotations

import io

import yaml

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions, LSLEnumType


def lsl_annotations(member) -> str:
    annotations = ""
    if member.private:
        annotations += " // private"
    if member.deprecated:
        annotations += " // deprecated"
    return annotations


@register("gen_enums_txt")
def gen_enums_txt(definitions: LSLDefinitions) -> str:
    builtins_str = "// Dump of the enums just for testing. Feel free to remove this rule\n"

    for enum in sorted(definitions.enums.values(), key=lambda x: x.name):
        builtins_str += f"enum {enum.name!s} {{\n"
        for member in sorted(enum.members, key=lambda x: x.value):
            builtins_str += f"  {member.name} = "
            if enum.type == LSLEnumType.FLAG:
                builtins_str += f"0x{member.value:x}"
            else:
                builtins_str += f"{member.value}"
            builtins_str += lsl_annotations(member.constant)
            builtins_str += "\n"
        builtins_str += "};\n"

    for const in sorted(definitions.constants.values(), key=lambda x: x.name):
        if not const.member_of:
            builtins_str += f"const {const.type!s} {const.name} = {const.lsl_doc_literal}"
            builtins_str += lsl_annotations(const)
            builtins_str += "\n"

    return builtins_str


@register("gen_category_functions")
def gen_category_functions(definitions: LSLDefinitions) -> str:
    file = io.StringIO()
    file.write("# Functions by category\n")
    categories = {}

    for event in sorted(definitions.events.values(), key=lambda x: x.name):
        for category in event.categories:
            builtins_str = f"{event.name}{event.args_str}"
            builtins_str += lsl_annotations(event)
            categories.setdefault(category, []).append(builtins_str)

    for func in sorted(definitions.functions.values(), key=lambda x: x.name):
        for category in func.categories:
            builtins_str = f"{func.name}{func.args_str} -> {func.ret_type!s}"
            builtins_str += lsl_annotations(func)
            categories.setdefault(category, []).append(builtins_str)

    categories = {k: categories[k] for k in sorted(categories.keys())}
    yaml.safe_dump(categories, file, sort_keys=False, width=200)
    return file.getvalue()


@register("gen_category_docs")
def gen_category_docs(definitions: LSLDefinitions) -> str:
    file = io.StringIO()
    file.write("# Functions by category\n")
    categories = {}

    for event in sorted(definitions.events.values(), key=lambda x: x.name):
        for category in event.categories:
            builtins_str = f"{event.name}{event.args_str}"
            builtins_str += lsl_annotations(event)
            categories.setdefault(category, []).append(builtins_str)

    for func in sorted(definitions.functions.values(), key=lambda x: x.name):
        for category in func.categories:
            builtins_str = f"{func.name}{func.args_str} -> {func.ret_type!s}"
            builtins_str += lsl_annotations(func)
            categories.setdefault(category, []).append(builtins_str)

    categories = {k: categories[k] for k in sorted(categories.keys())}
    yaml.safe_dump(categories, file, sort_keys=False, width=200)
    return file.getvalue()
