"""Code generators for LSL and SLua definitions."""

# Import all generator modules to trigger @register decorators
from lsl_definitions.generators import (
    builtins_txt,
    keywords,
    lscript,
    lscript_compiler,
    lsl,
    slua,
    slua_lsp_docs,
)
from lsl_definitions.generators.base import GENERATORS, register

__all__ = [
    "GENERATORS",
    "register",
    "builtins_txt",
    "keywords",
    "lscript",
    "lscript_compiler",
    "lsl",
    "slua",
    "slua_lsp_docs",
]
