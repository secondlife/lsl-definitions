#!/bin/env python3
# Importantly, this shebang line prevents the bytecode pre-compilation step from
# deciding that this script is Python 2. It is not.
"""
LSL Definitions Generator - CLI entry point.

This module provides the command-line interface for generating various output
formats from LSL and SLua definition files.
"""

from __future__ import annotations

import argparse
import inspect
import sys
from inspect import Parameter

from lsl_definitions.generators import GENERATORS
from lsl_definitions.lsl import LSLDefinitionParser
from lsl_definitions.slua import SLuaDefinitionParser
from lsl_definitions.utils import write_if_different


def main():
    argparser = argparse.ArgumentParser(description="Process LSL definitions.")
    argparser.add_argument("definitions", help="Path to the LSL definition yaml")

    subparsers = argparser.add_subparsers(dest="mode", required=True, metavar="<command>")

    # Build subparsers from generator registry
    for info in GENERATORS:
        sig = inspect.signature(info.func)
        sub = subparsers.add_parser(info.name, help=info.brief_help)

        needs_slua = False
        has_output_path = False

        for param_name, param in sig.parameters.items():
            # Skip special params handled by the CLI
            if param_name == "definitions":
                continue

            # Check for SLuaDefinitions type annotation
            if param.annotation == "SLuaDefinitions":
                needs_slua = True
                continue

            # Check if function handles its own output
            if param_name == "output_path":
                has_output_path = True

            if param.annotation == "bool":
                # bool = flag
                sub.add_argument(
                    f"--{param_name.replace('_', '-')}",
                    dest=param_name,
                    action="store_true",
                    default=param.default if param.default is not Parameter.empty else False,
                )
            elif param.annotation == "int":
                default = param.default if param.default is not Parameter.empty else None
                sub.add_argument(
                    param_name,
                    type=int,
                    default=default,
                    nargs="?" if default is not None else None,
                )
            else:
                # str or untyped = positional string argument
                default = param.default if param.default is not Parameter.empty else None
                sub.add_argument(
                    param_name, default=default, nargs="?" if default is not None else None
                )

        # Add slua_definitions positional arg if needed
        if needs_slua:
            sub.add_argument("slua_definitions", help="Path to the SLua definition yaml")

        # Add output_path if function doesn't declare it
        if not has_output_path:
            sub.add_argument("output_path", help="Output path (use '-' for stdout)")

        sub.set_defaults(
            generator_func=info.func,
            signature=sig,
            needs_slua=needs_slua,
            has_output_path=has_output_path,
        )

    parsed_args = argparser.parse_args()

    # Parse LSL definitions
    lsl_parser = LSLDefinitionParser()
    definitions = lsl_parser.parse_file(parsed_args.definitions)

    # Parse SLua definitions if needed
    slua_definitions = None
    if parsed_args.needs_slua:
        slua_parser = SLuaDefinitionParser()
        slua_definitions = slua_parser.parse_file(parsed_args.slua_definitions)

    # Build kwargs from parsed args based on function signature
    # This is a bit like how `click` works, but worse and janky.
    kwargs = {}
    for param_name, param in parsed_args.signature.parameters.items():
        if param_name == "definitions":
            continue
        if param.annotation == "SLuaDefinitions":
            kwargs["slua_definitions"] = slua_definitions
        elif hasattr(parsed_args, param_name):
            kwargs[param_name] = getattr(parsed_args, param_name)

    # Invoke the generator
    result = parsed_args.generator_func(definitions, **kwargs)

    # Write output (if function didn't handle it)
    if result is not None:
        output_path = parsed_args.output_path
        if output_path == "-":
            if isinstance(result, bytes):
                sys.stdout.buffer.write(result)
            else:
                print(result)
        else:
            write_if_different(output_path, result)


if __name__ == "__main__":
    main()
