#!/bin/env python3


import json
import sys

import jsonschema
import yaml


def validate_definitions_via_jsonschema(schema_filename, yaml_filename) -> None:
    with open(schema_filename, encoding="utf-8") as schema_file:
        schemadata = json.load(schema_file)
    with open(yaml_filename, encoding="utf-8") as yaml_file:
        yamldata = yaml.safe_load(yaml_file)

    try:
        jsonschema.validate(instance=yamldata, schema=schemadata)
        print(f"\nSUCCESS: Validated {yaml_filename} against the schema")
    except jsonschema.exceptions.ValidationError as e:
        print(f"\nVALIDATION ERROR: INVALID {yaml_filename}", file=sys.stderr)
        print(f"  Message: {e.message}", file=sys.stderr)
        print(f"  Path: {' -> '.join(map(str, e.path))}", file=sys.stderr)
        print(f"  Schema Path: {' -> '.join(map(str, e.schema_path))}", file=sys.stderr)
        raise e
    except jsonschema.exceptions.SchemaError as e:
        print(f"\nSCHEMA ERROR: The schema {schema_filename} is invalid", file=sys.stderr)
        print(f"  Message: {e.message}", file=sys.stderr)
        raise e
    except Exception as e:
        print(f"\nOh no ...: {e} processing {yaml_filename}", file=sys.stderr)
        raise e


from lsl_definitions.utils import LUAU_KEYWORDS


def validate_no_keyword_params() -> None:
    """Check that no function parameter name in either definitions file is a Luau keyword."""
    errors = []

    with open("lsl_definitions.yaml", encoding="utf-8") as f:
        lsl = yaml.safe_load(f)
    for func_name, func in lsl.get("functions", {}).items():
        for arg in func.get("arguments", []):
            for param_name in arg:
                if param_name in LUAU_KEYWORDS:
                    errors.append(
                        f"lsl_definitions.yaml: {func_name}.{param_name} is a Luau keyword"
                    )

    with open("slua_definitions.yaml", encoding="utf-8") as f:
        slua = yaml.safe_load(f)

    def check_params(func_name, params, source):
        for p in params or []:
            name = p.get("name", "")
            if name in LUAU_KEYWORDS:
                errors.append(f"{source}: {func_name}.{name} is a Luau keyword")

    for func in slua.get("functions", []):
        check_params(func["name"], func.get("parameters", []), "slua_definitions.yaml")
    for module in slua.get("modules", []):
        for func in module.get("functions", []):
            check_params(
                f"{module['name']}.{func['name']}",
                func.get("parameters", []),
                "slua_definitions.yaml",
            )
    for cls in slua.get("classes", []) + slua.get("base-classes", []):
        for method in cls.get("methods", []):
            check_params(
                f"{cls['name']}.{method['name']}",
                method.get("parameters", []),
                "slua_definitions.yaml",
            )

    if errors:
        for e in errors:
            print(f"KEYWORD PARAM ERROR: {e}", file=sys.stderr)
        raise ValueError(f"{len(errors)} parameter name(s) are Luau keywords")
    print("\nSUCCESS: No Luau keyword parameter names found")


def main():
    validate_definitions_via_jsonschema("lsl_definitions.schema.json", "lsl_definitions.yaml")
    validate_definitions_via_jsonschema("slua_definitions.schema.json", "slua_definitions.yaml")
    validate_no_keyword_params()


if __name__ == "__main__":
    main()
