"""Utility functions for LSL definitions processing."""

import enum
import os
import os.path
import stat
from typing import Iterable, Sequence, TypeVar, Union

CONTROL_PICTURES = range(0x2400, 0x2420)
"""Pass this to str.translate to display EOF and NAK prettier"""


def unescape_control_characters(s: str) -> str:
    s = s.replace("\\n", "\u240a")
    for i in range(0x20):
        s = s.replace(f"\\x{i:02x}", chr(0x2400 + i))
    return s


class StringEnum(str, enum.Enum):
    def __str__(self):
        return self.value


def to_c_str(val: str) -> str:
    # Unicode characters should be replaced with hex escapes.
    repr_val = repr(val.encode("utf-8"))
    assert '"' not in repr_val
    # Need to slice off the leading 'b' as well.
    return repr_val[2:-1]


def remove_worthless(val: dict) -> dict:
    """Remove attributes that have the same implied values when not present"""
    if not val.get("deprecated"):
        val.pop("deprecated", None)
    if not val.get("god-mode"):
        val.pop("god-mode", None)
    if not val.get("private"):
        val.pop("private", None)
    if not val.get("pure"):
        val.pop("pure", None)
    if not val.get("native"):
        val.pop("native", None)
    if not val.get("bool_semantics"):
        val.pop("bool_semantics", None)
    if not val.get("bool-semantics"):
        val.pop("bool-semantics", None)
    if not val.get("index-semantics"):
        val.pop("index-semantics", None)
    if not val.get("type-arguments"):
        val.pop("type-arguments", None)
    return val


def remove_nones(**kwargs) -> dict:
    """Remove any None values from a dict"""
    return {k: v for k, v in kwargs.items() if v is not None}


def splice_str(val: str, splice_by: str, replacement: str) -> str:
    split = val.split(splice_by, 1)
    if len(split) != 2:
        raise ValueError(f"Unable to splice by {splice_by!r}")
    return "\n".join((split[0], replacement, split[1]))


_T = TypeVar("_T")


def to_chunks(chunkable: Sequence[_T], chunk_size: int) -> Iterable[Sequence[_T]]:
    while chunkable:
        yield chunkable[:chunk_size]
        chunkable = chunkable[chunk_size:]


def is_uuid(val: str) -> bool:
    import re

    return bool(re.match(r"\A[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}\Z", val))


def write_if_different(filename: str, data: Union[bytes, str]):
    """
    Write, but not if it would change mtime needlessly

    That may mark a file dirty for build, which we don't want
    """
    if isinstance(data, str):
        data = data.encode("utf8")

    old_data = None
    if os.path.exists(filename) and stat.S_ISREG(os.stat(filename).st_mode):
        with open(filename, "rb") as f:
            old_data = f.read()

    if data != old_data:
        with open(filename, "wb") as f:
            f.write(data)
