#!/bin/env python3
# coding: utf-8


import json
import sys
import yaml

import jsonschema


def jsonschema() -> bool:
    with open('lsl_definitions.schema.json', 'r', encoding='utf-8') as schema_file:
        schemadata = json.load(schema_file)
    with open('lsl_definitions.yaml', 'r', encoding='utf-8') as yaml_file:
        yamldata = yaml.safe_load(yaml_file)

    try:
        jsonschema.validate(instance=yamldata, schema=schemadata)
        print(f"\nSUCCESS: Valid against the schema")
        return True
    except jsonschema.exceptions.ValidationError as e:
        print(f"\nVALIDATION ERROR: INVALID", file=sys.stderr)
        print(f"  Message: {e.message}", file=sys.stderr)
        print(f"  Path: {' -> '.join(map(str, e.path))}", file=sys.stderr)
        print(f"  Schema Path: {' -> '.join(map(str, e.schema_path))}", file=sys.stderr)
        return False
    except jsonschema.exceptions.SchemaError as e:
        print(f"\nSCHEMA ERROR: The schema is invalid", file=sys.stderr)
        print(f"  Message: {e.message}", file=sys.stderr)
        return False
    except Exception as e:
        print(f"\nOh no ...: {e}", file=sys.stderr)
        return False
