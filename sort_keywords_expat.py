from __future__ import annotations
import sys
from collections.abc import Callable, Iterator
from dataclasses import dataclass, field
from xml.parsers.expat import ParserCreate, ExpatError, errors

""" Sort a keywords LLSD XML for diffing."""

@dataclass
class RawLLSDXMLMap:
    header: bytes = b""
    items: dict[str, bytes | RawLLSDXMLMap] = field(default_factory=dict)
    footer: bytes = b""

    def iter_chunks(self) -> Iterator[bytes]:
        yield self.header
        for key, value in self.items.items():
            if isinstance(value, RawLLSDXMLMap):
                yield from value.iter_chunks()
            else:
                yield value
        yield self.footer
    
    def sort_items(self):
        self.items = dict(sorted(self.items.items(), key=lambda item: item[0]))
    
    def reorder_items(self, order: list[str]):
        self.items = {key: self.items[key] for key in order}

xml = open(sys.argv[1], "rb").read()

p = ParserCreate()
map_stack: list[RawLLSDXMLMap] = []
tag_stack: list[str] = []
key_stack: list[str] = []
offset = 0
closer: Callable[[], None] | None = None

def run_closer():
    global closer
    if closer is not None:
        closer()
        closer = None

def chunk() -> bytes:
    global offset
    chunk = xml[offset : p.CurrentByteIndex]
    offset = p.CurrentByteIndex
    return chunk

def map_start():
    map_stack.append(RawLLSDXMLMap(header=chunk()))
    key_stack.append("")

def map_end():
    map = map_stack.pop()
    map.footer = chunk()
    key_stack.pop()
    if key_stack:
        map_stack[-1].items[key_stack[-1]] = map
        key_stack[-1] = ""

def key_start(name: str):
    pass

def key_end():
    if key_stack[-1] != "":
        map_stack[-1].items[key_stack[-1]] = chunk()
        key_stack[-1] = ""


def start_element(name, attrs):
    tag_stack.append(name)
    if "array" in tag_stack:
        return
    global closer
    if name == "map":
        run_closer()
        closer = map_start
    elif name == "key":
        run_closer()
        key_end()
        key_start(name)
def end_element(name):
    global closer
    tag_stack.pop()
    if "array" in tag_stack:
        return
    if name == "map":
        run_closer()
        key_end()
        closer = map_end
def char_data(data):
    if "array" in tag_stack:
        return
    if tag_stack[-1] == "key":
        key_stack[-1] = data

try:
    p.StartElementHandler = start_element
    p.EndElementHandler = end_element
    p.CharacterDataHandler = char_data
    p.Parse(xml)
    result = map_stack[0]
    run_closer()
except ExpatError as err:
    print("Error:", errors.messages[err.code])

if "--nosort" not in sys.argv:
    for value in result.items.values():
        if isinstance(value, RawLLSDXMLMap):
            value.sort_items()

    if "--noreorder" not in sys.argv:
        result.reorder_items([
            "llsd-lsl-syntax-version",
            "controls",
            "types",
            "constants",
            "events",
            "functions",
        ])

for chunk in result.iter_chunks():
    sys.stdout.buffer.write(chunk)

