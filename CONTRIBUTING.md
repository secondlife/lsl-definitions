# Contributing to LSL Definitions

Thank you for your interest in contributing to the LSL definitions repository! This document outlines how you can help improve the LSL language specification.

## What We Accept

### ✅ Welcome Contributions
- **Documentation improvements** - clearer explanations, better examples
- **Tooltip enhancements** - more helpful descriptions for functions and parameters
- **Error corrections** - fixing typos, incorrect parameter types, or outdated information
- **Formatting improvements** - better YAML structure or consistency

### ❌ What We Don't Accept
- **New function requests** - this repository defines existing LSL functionality only
- **Language feature proposals** - new LSL capabilities are decided through official Second Life channels
- **API changes** - modifications to function signatures or behavior

## How to Contribute

 1. **Fork** this repository
 2. **Create a branch** for your changes (`git checkout -b improve-documentation`)
 3. **Make your changes** to `lsl_definitions.yaml`
 4. **Test** that your YAML is valid (See [Running validation locally](#running-validation-locally))
 5. **Commit** your changes with a clear message
 6. **Push** to your fork and **submit a pull request**

## Running validation locally

Validation is done with python and the validate.py script you will need to setup a python virtual environment and install the dependancies

### Setup
```bash
python -m venv .venv
source .venv/bin/activate
pip install ".[validate]"
```
Now you should be able to run the validation script as specified in the `pyproject.toml`
```bash
validate-lsl-definitions-via-jsonschema
```

## Pull Request Guidelines

- **Be specific** in your PR description about what you're improving
- **Keep changes focused** - one improvement per PR when possible
- **Maintain consistency** with existing formatting and style
- **Include examples** if you're improving documentation

## Questions or Suggestions?

For questions about LSL functionality or feature requests, please use official Second Life channels rather than this repository.

For questions about contributing to this repository, feel free to open an issue for discussion.
