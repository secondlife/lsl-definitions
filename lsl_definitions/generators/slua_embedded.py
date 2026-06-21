from __future__ import annotations

from string import Template

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions
from lsl_definitions.slua import SLuaDefinitions


@register("gen_slua_embedded_defs")
def gen_slua_embedded_defs(
    definitions: LSLDefinitions, template_path: str, slua_definitions: SLuaDefinitions
) -> str:
    """Generate SLua Embedded Definitions File."""

    # quaternion_module = slua_definitions.get_module("quaternion")
    # rotation_module = SLuaModule(
    #     name="rotation",
    #     comment=quaternion_module.comment,
    #     callable=quaternion_module.callable,
    #     constants=quaternion_module.constants,
    #     functions=quaternion_module.functions,
    # )
    # slua_definitions.modules.append(rotation_module)

    inserts = {
        #     SLUA_GLOBAL_FUNCTIONS_REGEX=get_slua_global_functions(slua_definitions),
        #     SLUA_GLOBAL_MODULES_REGEX=get_slua_modules(slua_definitions),
        #     SLUA_GLOBAL_CONSTANTS_REGEX=get_slua_global_constants(slua_definitions),
        #     SLUA_GLOBAL_LSL_CONSTANTS_REGEX=get_LL_constants(slua_definitions),
        #     SLUA_GLOBAL_LL_MODULE_REGEX=get_LL_module_functions(slua_definitions),
        #     SLUA_GLOBAL_LL_MODULE_DEPRECATED_REGEX=get_LL_module_deprecated_functions(slua_definitions),
        #     # nil|string|number|boolean|thread|userdata|symbol|vector|buffer|unknown|never|any
        #     SLUA_GLOBAL_TYPES_REGEX=get_slua_global_types(slua_definitions),
        #     SLUA_METAMETHODS_REGEX=get_slua_metamethods(slua_definitions),
        #     SLUA_GLOBAL_LL_VARIABLE_FUNCTIONS_REGEX=get_LL_variable_functions(slua_definitions),
        #     SLUA_GLOBAL_LL_VARIABLES_REGEX=get_LL_variables(slua_definitions),
    }

    with open(template_path) as f:
        template = Template(f.read())
        return template.substitute(inserts)
