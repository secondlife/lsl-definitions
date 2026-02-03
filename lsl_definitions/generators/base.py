"""Registry for code generators."""

from __future__ import annotations

from dataclasses import dataclass
from typing import Callable

GeneratorFunc = Callable[..., str | bytes | None]


@dataclass
class GeneratorInfo:
    name: str
    func: GeneratorFunc
    help: str

    @property
    def brief_help(self) -> str:
        return self.help.split("\n")[0] if self.help else ""


GENERATORS: list[GeneratorInfo] = []
"""Stores all the registered generators for dynamic lookup by the CLI"""


def register(name: str):
    """Decorator to register a generator function for CLI use."""

    def decorator(func: GeneratorFunc) -> GeneratorFunc:
        GENERATORS.append(GeneratorInfo(name, func, func.__doc__ or ""))
        return func

    return decorator
