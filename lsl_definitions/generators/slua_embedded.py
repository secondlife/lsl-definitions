from __future__ import annotations

import io
from string import Template

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions
from lsl_definitions.slua import SLuaDefinitions


@register("gen_slua_embedded_defs")
def gen_slua_embedded_defs(
    definitions: LSLDefinitions, template_path: str, slua_definitions: SLuaDefinitions
) -> str:
    """Generate SLua Embedded Definitions File."""

    inserts = {}
    with io.StringIO() as defs:
        defs.write("declare ")
        defs.write(slua_definitions.global_constants.pop("_G").to_luau_def())
        defs.write("\ndeclare ")
        defs.write(slua_definitions.global_constants.pop("_VERSION").to_luau_def())
        defs.write("\n")
        for func in slua_definitions.functions.values():
            if func.private or func.local_only:
                continue
            if func.slua_removed:
                continue
            if func.typechecker_flags.builtin:
                defs.write("-- ")
            func.write_luau_global_def(defs)
        inserts["GLOBAL_FUNCTIONS"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("bit32").write_luau_def(defs)
        inserts["BIT32_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("math").write_luau_def(defs)
        inserts["MATH_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        alias = slua_definitions.type_aliases.pop("DateTypeArg")
        alias.export = False
        defs.write(alias.to_luau_def())
        defs.write("\n")
        alias = slua_definitions.type_aliases.pop("DateTypeResult")
        alias.export = False
        defs.write(alias.to_luau_def())
        defs.write("\n")
        slua_definitions.modules.pop("os").write_luau_def(defs)
        inserts["OS_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("coroutine").write_luau_def(defs)
        inserts["COROUTINE_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("table").write_luau_def(defs)
        inserts["TABLE_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("debug").write_luau_def(defs)
        inserts["DEBUG_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("utf8").write_luau_def(defs)
        inserts["UTF8_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.modules.pop("buffer").write_luau_def(defs)
        inserts["BUFFER_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.base_classes.pop("vector").write_luau_def(defs)
        slua_definitions.modules.pop("vector").write_luau_def(defs)
        inserts["VECTOR_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.base_classes.pop("quaternion").write_luau_def(defs)
        slua_definitions.modules.pop("quaternion").write_luau_def(defs)
        var = slua_definitions.global_variables.pop("rotation")
        defs.write("declare ")
        defs.write(var.to_luau_def())
        defs.write("\n")
        inserts["QUATERNION_TABLE"] = defs.getvalue()
    with io.StringIO() as defs:
        slua_definitions.base_classes.pop("uuid").write_luau_def(defs)
        slua_definitions.modules.pop("uuid").write_luau_def(defs)
        inserts["UUID_TABLE"] = defs.getvalue()

    with open(template_path) as f:
        template = Template(f.read())
        return template.substitute(inserts)
