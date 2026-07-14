// This file is part of the Luau programming language and is licensed under MIT License; see LICENSE.txt for details
#include "Luau/BuiltinDefinitions.h"

LUAU_FASTFLAG(LuauIntegerLibrary)
LUAU_FASTFLAG(LuauIntegerType2)
LUAU_FASTFLAG(LuauAllowGlobalDeclarationToBeCalledClass)
LUAU_FASTFLAG(DebugLuauUserDefinedClasses)
LUAU_FASTFLAG(LuauUdtfTypeIsSubtypeOf)

namespace Luau
{

static constexpr const char* kBuiltinDefinitionBaseSrc = R"BUILTIN_SRC(

$GLOBAL_FUNCTIONS
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionBit32Src = R"BUILTIN_SRC(

$BIT32_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionMathSrc = R"BUILTIN_SRC(

$MATH_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionOsSrc = R"BUILTIN_SRC(

$OS_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionCoroutineSrc = R"BUILTIN_SRC(

$COROUTINE_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTableSrc = R"BUILTIN_SRC(

$TABLE_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionDebugSrc = R"BUILTIN_SRC(

$DEBUG_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionUtf8Src = R"BUILTIN_SRC(

$UTF8_TABLE
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionBufferSrc = R"BUILTIN_SRC(
--- Buffer API
declare buffer: {
    create: @checked (size: number) -> buffer,
    fromstring: @checked (str: string) -> buffer,
    tostring: @checked (b: buffer) -> string,
    len: @checked (b: buffer) -> number,
    copy: @checked (target: buffer, targetOffset: number, source: buffer, sourceOffset: number?, count: number?) -> (),
    fill: @checked (b: buffer, offset: number, value: number, count: number?) -> (),
    readi8: @checked (b: buffer, offset: number) -> number,
    readu8: @checked (b: buffer, offset: number) -> number,
    readi16: @checked (b: buffer, offset: number) -> number,
    readu16: @checked (b: buffer, offset: number) -> number,
    readi32: @checked (b: buffer, offset: number) -> number,
    readu32: @checked (b: buffer, offset: number) -> number,
    readf32: @checked (b: buffer, offset: number) -> number,
    readf64: @checked (b: buffer, offset: number) -> number,
    writei8: @checked (b: buffer, offset: number, value: number) -> (),
    writeu8: @checked (b: buffer, offset: number, value: number) -> (),
    writei16: @checked (b: buffer, offset: number, value: number) -> (),
    writeu16: @checked (b: buffer, offset: number, value: number) -> (),
    writei32: @checked (b: buffer, offset: number, value: number) -> (),
    writeu32: @checked (b: buffer, offset: number, value: number) -> (),
    writef32: @checked (b: buffer, offset: number, value: number) -> (),
    writef64: @checked (b: buffer, offset: number, value: number) -> (),
    readstring: @checked (b: buffer, offset: number, count: number) -> string,
    writestring: @checked (b: buffer, offset: number, value: string, count: number?) -> (),
    readbits: @checked (b: buffer, bitOffset: number, bitCount: number) -> number,
    writebits: @checked (b: buffer, bitOffset: number, bitCount: number, value: number) -> (),
    readinteger: @checked (b: buffer, offset: number) -> integer,
    writeinteger: @checked (b: buffer, offset: number, value: integer) -> (),
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionBufferSrc_NOINTEGER = R"BUILTIN_SRC(

$BUFFER_TABLE
)BUILTIN_SRC";

static const char* const kBuiltinDefinitionQuaternionSrc = R"BUILTIN_SRC(

$QUATERNION_TABLE
)BUILTIN_SRC";

static const char* const kBuiltinDefinitionVectorSrc = R"BUILTIN_SRC(

$VECTOR_TABLE
)BUILTIN_SRC";

static const char* const kBuiltinDefinitionUuidSrc = R"BUILTIN_SRC(

$UUID_TABLE
)BUILTIN_SRC";

static const char* const kBuiltinDefinitionIntegerSrc = R"BUILTIN_SRC(

declare integer: {
    create: @checked (x: number) -> integer,
    tonumber: @checked (x: integer) -> number,
    neg: @checked (value: integer) -> integer,
    add: @checked (x: integer, y: integer) -> integer,
    sub: @checked (x: integer, y: integer) -> integer,
    mul: @checked (x: integer, y: integer) -> integer,
    div: @checked (x: integer, y: integer) -> integer,
    rem: @checked (x: integer, y: integer) -> integer,
    idiv: @checked (x: integer, y: integer) -> integer,
    mod: @checked (x: integer, y: integer) -> integer,
    udiv: @checked (x: integer, y: integer) -> integer,
    urem: @checked (x: integer, y: integer) -> integer,
    min: @checked (integer, ...integer) -> integer,
    max: @checked (integer, ...integer) -> integer,
    band: @checked (...integer) -> integer,
    bor: @checked (...integer) -> integer,
    bnot: @checked (x: integer) -> integer,
    bxor: @checked (...integer) -> integer,
    lt: @checked (x: integer, y: integer) -> boolean,
    le: @checked (x: integer, y: integer) -> boolean,
    ult: @checked (x: integer, y: integer) -> boolean,
    ule: @checked (x: integer, y: integer) -> boolean,
    gt: @checked (x: integer, y: integer) -> boolean,
    ge: @checked (x: integer, y: integer) -> boolean,
    ugt: @checked (x: integer, y: integer) -> boolean,
    uge: @checked (x: integer, y: integer) -> boolean,
    lshift: @checked (x: integer, numBitPositions: integer) -> integer,
    rshift: @checked (x: integer, numBitPositions: integer) -> integer,
    arshift: @checked (x: integer, numBitPositions: integer) -> integer,
    lrotate: @checked (x: integer, numBitPositions: integer) -> integer,
    rrotate: @checked (x: integer, numBitPositions: integer) -> integer,
    extract: @checked (value: integer, bitPosition: integer, numBits: integer?) -> integer,
    replace: @checked (value: integer, replacement: integer, bitPosition: integer, numBits: integer?) -> integer,
    clamp: @checked (value: integer, min: integer, max: integer) -> integer,
    btest: @checked (...integer) -> boolean,
    countrz: @checked (x: integer) -> integer,
    countlz: @checked (x: integer) -> integer,
    bswap: @checked (x: integer) -> integer,
    fromstring: @checked (str: string, base: number?) -> integer,
    minsigned: integer,
    maxsigned: integer
}

)BUILTIN_SRC";

static const char* kBuiltinDefinitionClassSrc = R"CLASS_SRC(
declare class: {
    isinstance: @checked (o: unknown, c: class) -> boolean,
    classof: @checked (o: unknown) -> class?
}
)CLASS_SRC";

std::string getBuiltinDefinitionSource()
{
    std::string result = kBuiltinDefinitionBaseSrc;

    result += kBuiltinDefinitionBit32Src;
    result += kBuiltinDefinitionMathSrc;
    result += kBuiltinDefinitionOsSrc;
    result += kBuiltinDefinitionCoroutineSrc;
    result += kBuiltinDefinitionTableSrc;
    result += kBuiltinDefinitionDebugSrc;
    result += kBuiltinDefinitionUtf8Src;
    if (FFlag::LuauIntegerType2 && FFlag::LuauIntegerLibrary)
        result += kBuiltinDefinitionBufferSrc;
    else
        result += kBuiltinDefinitionBufferSrc_NOINTEGER;

    result += kBuiltinDefinitionVectorSrc;
    result += kBuiltinDefinitionQuaternionSrc;
    result += kBuiltinDefinitionUuidSrc;

    if (FFlag::LuauIntegerType2 && FFlag::LuauIntegerLibrary)
    {
        result += kBuiltinDefinitionIntegerSrc;
    }

    if (FFlag::DebugLuauUserDefinedClasses && FFlag::LuauAllowGlobalDeclarationToBeCalledClass)
    {
        result += kBuiltinDefinitionClassSrc;
    }

    return result;
}

// TODO: split into separate tagged unions when the new solver can appropriately handle that.
static constexpr const char* kBuiltinDefinitionTypeMethodSrc = R"BUILTIN_SRC(

export type type = {
    tag: "nil" | "unknown" | "never" | "any" | "boolean" | "number" | "integer" | "string" | "buffer" | "thread" |
         "singleton" | "negation" | "union" | "intersection" | "table" | "function" | "extern" | "generic",

    is: (self: type, arg: string) -> boolean,
    issubtypeof: (self: type, arg: type) -> boolean,

    -- for singleton type
    value: (self: type) -> (string | boolean | nil),

    -- for negation type
    inner: (self: type) -> type,

    -- for union and intersection types
    components: (self: type) -> {type},

    -- for table type
    setproperty: (self: type, key: type, value: type?) -> (),
    setreadproperty: (self: type, key: type, value: type?) -> (),
    setwriteproperty: (self: type, key: type, value: type?) -> (),
    readproperty: (self: type, key: type) -> type?,
    writeproperty: (self: type, key: type) -> type?,
    properties: (self: type) -> { [type]: { read: type?, write: type? } },
    setindexer: (self: type, index: type, result: type) -> (),
    setreadindexer: (self: type, index: type, result: type) -> (),
    setwriteindexer: (self: type, index: type, result: type) -> (),
    indexer: (self: type) -> { index: type, readresult: type, writeresult: type }?,
    readindexer: (self: type) -> { index: type, result: type }?,
    writeindexer: (self: type) -> { index: type, result: type }?,
    setmetatable: (self: type, arg: type) -> (),
    metatable: (self: type) -> type?,

    -- for function type
    setparameters: (self: type, head: {type}?, tail: type?) -> (),
    parameters: (self: type) -> { head: {type}?, tail: type? },
    setreturns: (self: type, head: {type}?, tail: type? ) -> (),
    returns: (self: type) -> { head: {type}?, tail: type? },
    setgenerics: (self: type, {type}?) -> (),
    generics: (self: type) -> {type},

    -- for class type
    -- 'properties', 'metatable', 'indexer', 'readindexer' and 'writeindexer' are shared with table type
    readparent: (self: type) -> type?,
    writeparent: (self: type) -> type?,

    -- for generic type
    name: (self: type) -> string?,
    ispack: (self: type) -> boolean,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTypeMethodSrc_NOISSUBTYPEOF = R"BUILTIN_SRC(

export type type = {
    tag: "nil" | "unknown" | "never" | "any" | "boolean" | "number" | "integer" | "string" | "buffer" | "thread" |
         "singleton" | "negation" | "union" | "intersection" | "table" | "function" | "extern" | "generic",

    is: (self: type, arg: string) -> boolean,

    -- for singleton type
    value: (self: type) -> (string | boolean | nil),

    -- for negation type
    inner: (self: type) -> type,

    -- for union and intersection types
    components: (self: type) -> {type},

    -- for table type
    setproperty: (self: type, key: type, value: type?) -> (),
    setreadproperty: (self: type, key: type, value: type?) -> (),
    setwriteproperty: (self: type, key: type, value: type?) -> (),
    readproperty: (self: type, key: type) -> type?,
    writeproperty: (self: type, key: type) -> type?,
    properties: (self: type) -> { [type]: { read: type?, write: type? } },
    setindexer: (self: type, index: type, result: type) -> (),
    setreadindexer: (self: type, index: type, result: type) -> (),
    setwriteindexer: (self: type, index: type, result: type) -> (),
    indexer: (self: type) -> { index: type, readresult: type, writeresult: type }?,
    readindexer: (self: type) -> { index: type, result: type }?,
    writeindexer: (self: type) -> { index: type, result: type }?,
    setmetatable: (self: type, arg: type) -> (),
    metatable: (self: type) -> type?,

    -- for function type
    setparameters: (self: type, head: {type}?, tail: type?) -> (),
    parameters: (self: type) -> { head: {type}?, tail: type? },
    setreturns: (self: type, head: {type}?, tail: type? ) -> (),
    returns: (self: type) -> { head: {type}?, tail: type? },
    setgenerics: (self: type, {type}?) -> (),
    generics: (self: type) -> {type},

    -- for class type
    -- 'properties', 'metatable', 'indexer', 'readindexer' and 'writeindexer' are shared with table type
    readparent: (self: type) -> type?,
    writeparent: (self: type) -> type?,

    -- for generic type
    name: (self: type) -> string?,
    ispack: (self: type) -> boolean,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTypeMethodSrc_NOINTEGER = R"BUILTIN_SRC(

export type type = {
    tag: "nil" | "unknown" | "never" | "any" | "boolean" | "number" | "string" | "buffer" | "thread" |
         "singleton" | "negation" | "union" | "intersection" | "table" | "function" | "extern" | "generic",

    is: (self: type, arg: string) -> boolean,
    issubtypeof: (self: type, arg: type) -> boolean,

    -- for singleton type
    value: (self: type) -> (string | boolean | nil),

    -- for negation type
    inner: (self: type) -> type,

    -- for union and intersection types
    components: (self: type) -> {type},

    -- for table type
    setproperty: (self: type, key: type, value: type?) -> (),
    setreadproperty: (self: type, key: type, value: type?) -> (),
    setwriteproperty: (self: type, key: type, value: type?) -> (),
    readproperty: (self: type, key: type) -> type?,
    writeproperty: (self: type, key: type) -> type?,
    properties: (self: type) -> { [type]: { read: type?, write: type? } },
    setindexer: (self: type, index: type, result: type) -> (),
    setreadindexer: (self: type, index: type, result: type) -> (),
    setwriteindexer: (self: type, index: type, result: type) -> (),
    indexer: (self: type) -> { index: type, readresult: type, writeresult: type }?,
    readindexer: (self: type) -> { index: type, result: type }?,
    writeindexer: (self: type) -> { index: type, result: type }?,
    setmetatable: (self: type, arg: type) -> (),
    metatable: (self: type) -> type?,

    -- for function type
    setparameters: (self: type, head: {type}?, tail: type?) -> (),
    parameters: (self: type) -> { head: {type}?, tail: type? },
    setreturns: (self: type, head: {type}?, tail: type? ) -> (),
    returns: (self: type) -> { head: {type}?, tail: type? },
    setgenerics: (self: type, {type}?) -> (),
    generics: (self: type) -> {type},

    -- for class type
    -- 'properties', 'metatable', 'indexer', 'readindexer' and 'writeindexer' are shared with table type
    readparent: (self: type) -> type?,
    writeparent: (self: type) -> type?,

    -- for generic type
    name: (self: type) -> string?,
    ispack: (self: type) -> boolean,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTypeMethodSrc_DEPRECATED = R"BUILTIN_SRC(

export type type = {
    tag: "nil" | "unknown" | "never" | "any" | "boolean" | "number" | "string" | "buffer" | "thread" |
         "singleton" | "negation" | "union" | "intersection" | "table" | "function" | "extern" | "generic",

    is: (self: type, arg: string) -> boolean,

    -- for singleton type
    value: (self: type) -> (string | boolean | nil),

    -- for negation type
    inner: (self: type) -> type,

    -- for union and intersection types
    components: (self: type) -> {type},

    -- for table type
    setproperty: (self: type, key: type, value: type?) -> (),
    setreadproperty: (self: type, key: type, value: type?) -> (),
    setwriteproperty: (self: type, key: type, value: type?) -> (),
    readproperty: (self: type, key: type) -> type?,
    writeproperty: (self: type, key: type) -> type?,
    properties: (self: type) -> { [type]: { read: type?, write: type? } },
    setindexer: (self: type, index: type, result: type) -> (),
    setreadindexer: (self: type, index: type, result: type) -> (),
    setwriteindexer: (self: type, index: type, result: type) -> (),
    indexer: (self: type) -> { index: type, readresult: type, writeresult: type }?,
    readindexer: (self: type) -> { index: type, result: type }?,
    writeindexer: (self: type) -> { index: type, result: type }?,
    setmetatable: (self: type, arg: type) -> (),
    metatable: (self: type) -> type?,

    -- for function type
    setparameters: (self: type, head: {type}?, tail: type?) -> (),
    parameters: (self: type) -> { head: {type}?, tail: type? },
    setreturns: (self: type, head: {type}?, tail: type? ) -> (),
    returns: (self: type) -> { head: {type}?, tail: type? },
    setgenerics: (self: type, {type}?) -> (),
    generics: (self: type) -> {type},

    -- for class type
    -- 'properties', 'metatable', 'indexer', 'readindexer' and 'writeindexer' are shared with table type
    readparent: (self: type) -> type?,
    writeparent: (self: type) -> type?,

    -- for generic type
    name: (self: type) -> string?,
    ispack: (self: type) -> boolean,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTypesLibSrc = R"BUILTIN_SRC(

declare types: {
    unknown: type,
    never: type,
    any: type,
    boolean: type,
    number: type,
    string: type,
    thread: type,
    buffer: type,
    integer: type,

    singleton: @checked (arg: string | boolean | nil) -> type,
    optional: @checked (arg: type) -> type,
    generic: @checked (name: string, ispack: boolean?) -> type,
    negationof: @checked (arg: type) -> type,
    unionof: @checked (...type) -> type,
    intersectionof: @checked (...type) -> type,
    newtable: @checked (props: {[type]: type} | {[type]: { read: type?, write: type? } }?, indexer: { index: type, readresult: type, writeresult: type }?, metatable: type?) -> type,
    newfunction: @checked (parameters: { head: {type}?, tail: type? }?, returns: { head: {type}?, tail: type? }?, generics: {type}?) -> type,
    copy: @checked (arg: type) -> type,
}
)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTypesLibSrc_NOINTEGER = R"BUILTIN_SRC(

declare types: {
    unknown: type,
    never: type,
    any: type,
    boolean: type,
    number: type,
    string: type,
    thread: type,
    buffer: type,

    singleton: @checked (arg: string | boolean | nil) -> type,
    optional: @checked (arg: type) -> type,
    generic: @checked (name: string, ispack: boolean?) -> type,
    negationof: @checked (arg: type) -> type,
    unionof: @checked (...type) -> type,
    intersectionof: @checked (...type) -> type,
    newtable: @checked (props: {[type]: type} | {[type]: { read: type?, write: type? } }?, indexer: { index: type, readresult: type, writeresult: type }?, metatable: type?) -> type,
    newfunction: @checked (parameters: { head: {type}?, tail: type? }?, returns: { head: {type}?, tail: type? }?, generics: {type}?) -> type,
    copy: @checked (arg: type) -> type,
}
)BUILTIN_SRC";

std::string getTypeFunctionDefinitionSource()
{
    std::string result;

    if (FFlag::LuauUdtfTypeIsSubtypeOf && FFlag::LuauIntegerType2)
        result += kBuiltinDefinitionTypeMethodSrc;
    else if (FFlag::LuauUdtfTypeIsSubtypeOf)
        result += kBuiltinDefinitionTypeMethodSrc_NOINTEGER;
    else if (FFlag::LuauIntegerType2)
        result += kBuiltinDefinitionTypeMethodSrc_NOISSUBTYPEOF;
    else
        result += kBuiltinDefinitionTypeMethodSrc_DEPRECATED;

    if (FFlag::LuauIntegerType2)
        result += kBuiltinDefinitionTypesLibSrc;
    else
        result += kBuiltinDefinitionTypesLibSrc_NOINTEGER;

    return result;
}

} // namespace Luau
