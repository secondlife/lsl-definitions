"""Generators for LSL script test files."""

from __future__ import annotations

import itertools
import os
import os.path

from lsl_definitions.generators.base import register
from lsl_definitions.lsl import LSLDefinitions, LSLType
from lsl_definitions.utils import to_chunks


@register("gen_constant_lsl_script")
def gen_constant_lsl_script(definitions: LSLDefinitions) -> str:
    """Generate a script to determine constants' effective values

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
    return "list l = [%s];\ndefault{\n%s\n}" % (joined_names, event_handlers)


@register("gen_func_call_scripts")
def gen_func_call_scripts(definitions: LSLDefinitions, output_path: str) -> None:
    """Generate scripts that call every known function

    Useful for verifying that a compiler agrees with our function definitions.

    Note: This generator handles its own IO since it writes multiple files.
    """

    # Ensure our output directory exists first
    os.makedirs(output_path, exist_ok=True)

    # Unfortunately, LSO scripts are the only things that actually use function IDs, which we need to test.
    # They're also limited to 16k. For that reason, we need to chunk the calls up between multiple scripts
    # so that we don't collide heap and stack when compiling.
    for i, chunk in enumerate(to_chunks(list(definitions.functions.values()), 300)):
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
