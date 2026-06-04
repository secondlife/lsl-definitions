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
- **AI-assisted PRs** - See [AGENTS.md](AGENTS.md). You may _only_ use AI if you're already an established contributor.

## How to Contribute

 1. **Fork** this repository
 2. **Create a branch** for your changes (`git checkout -b improve-documentation`)
 3. **Make your changes** to `lsl_definitions.yaml` and `slua_definitions.yaml`
 4. **Build** and validate the generated files. See [Building the generated files](#running-validation-locally))
 5. **Commit** your changes with a clear message
 6. **Push** to your fork and **submit a pull request**

## Building the generated files

Most changes to the yaml scripts will result in changes to the generated files. Please run the build step before submitting a pull request

Validation is done with python and the validate.py script you will need to setup a python virtual environment and install the dependancies

### Setup

Before you can build the generated files, you need to set up a python virtual environment and install the dependancies

```bash
python -m venv .venv
source .venv/bin/activate
pip install ".[validate]" pre-commit
```

### Building

Update any generated files that your edits will modify:
```bash
source .venv/bin/activate
bash gen_all_definitions.sh
```

### Validating (optional)

Make sure any changes you made pass the automated checks:
```bash
source .venv/bin/activate
validate-lsl-definitions-via-jsonschema
pre-commit run --all
```

## Pull Request Guidelines

- **Be specific** in your PR description about what you're improving
- **Keep changes focused** - one improvement per PR when possible
- **Maintain consistency** with existing formatting and style
- **Include examples** if you're improving documentation
- **Run** the generated file builder
- **No AI Prose in PRs or commit messages** - You as a human must describe to other humans what has been done.

## Questions or Suggestions?

For questions about LSL functionality or feature requests, please use official Second Life channels rather than this repository.

For questions about contributing to this repository, feel free to open an issue for discussion.
