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
            if member.constant.private:
                builtins_str += " // private"
            if member.constant.deprecated:
                builtins_str += " // deprecated"
            builtins_str += "\n"
        builtins_str += "};\n"

    for const in sorted(definitions.constants.values(), key=lambda x: x.name):
        if not const.member_of:
            builtins_str += f"const {const.type!s} {const.name} = {const.lsl_doc_literal}"
            if const.private:
                builtins_str += " // private"
            if const.deprecated:
                builtins_str += " // deprecated"
            builtins_str += "\n"

    return builtins_str


@register("gen_category_functions")
def gen_category_functions(definitions: LSLDefinitions) -> str:
    file = io.StringIO()
    file.write("# Functions by category\n")
    categories = {}

    for func in sorted(definitions.functions.values(), key=lambda x: x.name):
        for category in func.categories:
            categories.setdefault(category, []).append(func.name)

    categories = {k: categories[k] for k in sorted(categories.keys())}
    yaml.safe_dump(categories, file, sort_keys=False)
    return file.getvalue()
