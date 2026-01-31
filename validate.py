#!/bin/env python3
# coding: utf-8


import json
import sys

import jsonschema
import yaml


def validate_definitions_via_jsonschema(schema_filename, yaml_filename) -> None:
    with open(schema_filename, "r", encoding="utf-8") as schema_file:
        schemadata = json.load(schema_file)
    with open(yaml_filename, "r", encoding="utf-8") as yaml_file:
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


def main():
    validate_definitions_via_jsonschema("lsl_definitions.schema.json", "lsl_definitions.yaml")
    validate_definitions_via_jsonschema("slua_definitions.schema.json", "slua_definitions.yaml")


if __name__ == "__main__":
    main()
