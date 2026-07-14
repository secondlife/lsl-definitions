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

declare _G: any
declare _VERSION: string
declare function assert<T>(value: T?, errorMessage: string?): T -- magic type
declare function dangerouslyexecuterequiredmodule(f: (...any) -> ...any): ...any
declare function error<T>(message: T, level: number?): never
declare function gcinfo(): number
-- declare function getmetatable<T>(obj: T): getmetatable<T> -- builtin
declare function ipairs<V>(tab: {V}): (({V}, number) -> (number?, V), {V}, number)
@checked declare function newproxy(mt: boolean?): any
-- declare function next<K, V>(t: {[K]: V}, i: K?): (K?, V) -- builtin
-- declare function pairs<K, V>(t: {[K]: V}): (({[K]: V}, K?) -> (K?, V), {[K]: V}, K) -- builtin
declare function pcall<A..., R...>(f: (A...) -> R..., ...: A...): (boolean, R...)
declare function print<T...>(...: T...): ()
declare function rawequal<T1, T2>(a: T1, b: T2): boolean
declare function rawget<K, V>(t: {[K]: V}, k: K): V?
declare function rawlen<K, V>(t: {[K]: V} | string): number
declare function rawset<K, V>(t: {[K]: V}, k: K, v: V): {[K]: V}
@checked declare function require(target: any): any -- magic type
declare function select<A...>(i: string | number, ...: A...): ...any -- magic type
-- declare function setmetatable<T, MT>(t: T, mt: MT): setmetatable<T, MT> -- builtin, magic type
declare function tonumber(value: string? | number, base: number?): number?
declare function toquaternion(value: string? | quaternion): quaternion?
declare function torotation(value: string? | quaternion): quaternion?
declare function tostring<T>(value: T): string
declare function touuid(val: string? | buffer | uuid): uuid?
declare function tovector(val: string? | vector): vector?
declare function type<T>(obj: T): string
declare function typeof<T>(obj: T): string
declare function unpack<V>(tab: {V}, i: number?, j: number?): ...V
declare function xpcall<E, A..., R1..., R2...>(f: (A...) -> R1..., err: (E) -> R2..., ...: A...): (boolean, R1...)

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionBit32Src = R"BUILTIN_SRC(

declare bit32: {
  arshift: @checked (n: number, i: number) -> number,
  band: @checked (...number) -> number,
  bnot: @checked (n: number) -> number,
  bor: @checked (...number) -> number,
  bxor: @checked (...number) -> number,
  btest: @checked (...number) -> boolean,
  extract: @checked (n: number, field: number, width: number?) -> number,
  lrotate: @checked (n: number, i: number) -> number,
  lshift: @checked (n: number, i: number) -> number,
  replace: @checked (n: number, v: number, field: number, width: number?) -> number,
  rrotate: @checked (n: number, i: number) -> number,
  rshift: @checked (n: number, i: number) -> number,
  s32: @checked (n: number) -> number,
  smul: @checked (a: number, b: number) -> number,
  countlz: @checked (n: number) -> number,
  countrz: @checked (n: number) -> number,
  byteswap: @checked (n: number) -> number,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionMathSrc = R"BUILTIN_SRC(

declare math: {
  pi: number,
  huge: number,
  abs: @checked (n: number) -> number,
  acos: @checked (n: number) -> number,
  asin: @checked (n: number) -> number,
  atan: @checked (n: number) -> number,
  atan2: @checked (y: number, x: number) -> number,
  ceil: @checked (n: number) -> number,
  clamp: @checked (n: number, min: number, max: number) -> number,
  cos: @checked (n: number) -> number,
  cosh: @checked (n: number) -> number,
  deg: @checked (n: number) -> number,
  exp: @checked (n: number) -> number,
  floor: @checked (n: number) -> number,
  fmod: @checked (x: number, y: number) -> number,
  frexp: @checked (n: number) -> (number, number),
  ldexp: @checked (s: number, e: number) -> number,
  lerp: @checked (a: number, b: number, t: number) -> number,
  log: @checked (n: number, base: number?) -> number,
  log10: @checked (n: number) -> number,
  map: @checked (n: number, inMin: number, inMax: number, outMin: number, outMax: number) -> number,
  max: @checked (n: number, ...number) -> number,
  min: @checked (n: number, ...number) -> number,
  modf: @checked (n: number) -> (number, number),
  noise: @checked (x: number, y: number?, z: number?) -> number,
  pow: @checked (base: number, exponent: number) -> number,
  rad: @checked (n: number) -> number,
  random: @checked (min: number?, max: number?) -> number,
  randomseed: @checked @[deprecated {reason='Disabled in SLua.'}](seed: number) -> (),
  round: @checked (n: number) -> number,
  sign: @checked (n: number) -> number,
  sin: @checked (n: number) -> number,
  sinh: @checked (n: number) -> number,
  sqrt: @checked (n: number) -> number,
  tan: @checked (n: number) -> number,
  tanh: @checked (n: number) -> number,
  isnan: @checked (n: number) -> boolean,
  isinf: @checked (n: number) -> boolean,
  isfinite: @checked (n: number) -> boolean,
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionOsSrc = R"BUILTIN_SRC(

type DateTypeArg = {
  year: number,
  month: number,
  day: number,
  hour: number?,
  min: number?,
  sec: number?,
  isdst: boolean?,
}
type DateTypeResult = {
  year: number,
  month: number,
  wday: number,
  yday: number,
  day: number,
  hour: number,
  min: number,
  sec: number,
  isdst: boolean,
}
declare os: {
  clock: () -> number,
  date: ((formatString: string?, t: number?) -> string)
    & ((formatString: "*t" | "!*t", t: number?) -> DateTypeResult),
  difftime: @[deprecated {reason='Same as a - b'}](a: number, b: number) -> number,
  time: ((time: DateTypeArg) -> number?)
    & (() -> number),
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionCoroutineSrc = R"BUILTIN_SRC(

declare coroutine: {
  create: <A..., R...>(f: (A...) -> R...) -> thread,
  resume: <A..., R...>(co: thread, A...) -> (boolean, R...),
  running: () -> thread?,
  status: @checked (co: thread) -> "running" | "suspended" | "normal" | "dead",
  wrap: <A..., R...>(f: (A...) -> R...) -> (A...) -> R...,
  yield: <A..., R...>(A...) -> R...,
  isyieldable: () -> boolean,
  close: @checked (co: thread) -> (boolean, string?),
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionTableSrc = R"BUILTIN_SRC(

declare table: {
  concat: (a: {string | number}, sep: string?, i: number?, j: number?) -> string,
  foreach: @[deprecated {reason='Use a for loop instead'}]<K, V, R>(t: {[K]: V}, f: (key: K, value: V) -> R?) -> R?,
  foreachi: @[deprecated {reason='Use a for loop instead'}]<V, R>(a: {V}, f: (index: number, value: V) -> R?) -> R?,
  getn: @[deprecated {use='#'}](a: {any}) -> number,
  maxn: (t: {any}) -> number,
  insert: (<V>(a: {V}, i: number, value: V) -> ())
    & (<V>(a: {V}, value: V) -> ()),
  append: <V>(a: {V}, ...V) -> (),
  extend: <V>(a: {V}, b: {V}) -> {V},
  remove: <V>(a: {V}, i: number?) -> V?,
  sort: <V>(a: {V}, f: ((a: V, b: V) -> boolean)?) -> (),
  pack: <V>(...V) -> { n: number, [number]: V }, -- magic type
  unpack: <V>(a: {V}, i: number?, j: number?) -> ...V,
  move: <V>(src: {V}, i: number, j: number, d: number, dest: {V}?) -> {V},
  create: <V>(n: number, v: V?) -> {V},
  find: <V>(t: {V}, v: V, i: number?) -> number?,
  clear: (t: {}) -> (),
  shrink: <V>(t: {V}, shrink_sparse: boolean?) -> {V},
  freeze: <table>(t: table) -> table, -- magic type
  isfrozen: (t: {}) -> boolean,
  clone: <table>(t: table) -> table, -- magic type
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionDebugSrc = R"BUILTIN_SRC(

declare debug: {
  info: ((co: thread | ((...any) -> ...any) | number, level: number, s: string) -> ...any)
    & ((level: number, s: string) -> ...any)
    & ((func: (...any) -> ...any, s: string) -> ...any),
  traceback: ((co: thread, msg: string?, level: number?) -> string)
    & ((msg: string?, level: number?) -> string),
}

)BUILTIN_SRC";

static constexpr const char* kBuiltinDefinitionUtf8Src = R"BUILTIN_SRC(

declare utf8: {
  charpattern: string,
  char: @checked (...number) -> string,
  codes: @checked (src: string) -> ((string, number) -> (number, number), string, number),
  codepoint: @checked (src: string, start_index: number?, end_index: number?) -> ...number,
  len: @checked (str: string, start_index: number?, end_index: number?) -> (number?, number?),
  offset: @checked (str: string, n: number, start_index: number?) -> number?,
}

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

declare buffer: {
  create: @checked (size: number) -> buffer,
  fromstring: @checked (str: string) -> buffer,
  tostring: @checked (b: buffer) -> string,
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
  len: @checked (b: buffer) -> number,
  copy: @checked (target: buffer, targetOffset: number, source: buffer, sourceOffset: number?, count: number?) -> (),
  fill: @checked (b: buffer, offset: number, value: number, count: number?) -> (),
  readbits: @checked (b: buffer, bitOffset: number, bitCount: number) -> number,
  writebits: @checked (b: buffer, bitOffset: number, bitCount: number, value: number) -> (),
}

)BUILTIN_SRC";

static const char* const kBuiltinDefinitionQuaternionSrc = R"BUILTIN_SRC(

declare extern type quaternion with
  x: number
  y: number
  z: number
  s: number
  function __add(self, other: quaternion): quaternion
  function __sub(self, other: quaternion): quaternion
  function __mul(self, other: quaternion): quaternion
  function __div(self, other: quaternion): quaternion
  function __unm(self): quaternion
  function __eq(self, other: quaternion): boolean
  function __tostring(self): string
end

declare quaternion: ((x: number, y: number, z: number, s: number) -> quaternion) & {
  identity: quaternion,
  create: (x: number, y: number, z: number, s: number) -> quaternion,
  normalize: (q: quaternion) -> quaternion,
  magnitude: (q: quaternion) -> number,
  dot: (a: quaternion, b: quaternion) -> number,
  slerp: (a: quaternion, b: quaternion, t: number) -> quaternion,
  conjugate: (q: quaternion) -> quaternion,
  tofwd: (q: quaternion) -> vector,
  toleft: (q: quaternion) -> vector,
  toup: (q: quaternion) -> vector,
}
declare rotation: typeof(quaternion)

)BUILTIN_SRC";

static const char* const kBuiltinDefinitionVectorSrc = R"BUILTIN_SRC(

declare extern type vector with
  x: number
  y: number
  z: number
  function __add(self, other: vector): vector
  function __sub(self, other: vector): vector
  function __unm(self): vector
  function __mul(self, other: number | vector | quaternion): vector
  function __div(self, other: number | vector | quaternion): vector
  function __mod(self, other: vector): vector
  function __tostring(self): string
end

declare vector: ((x: number, y: number, z: number?) -> vector) & {
  zero: vector,
  one: vector,
  create: (x: number, y: number, z: number?) -> vector,
  magnitude: (v: vector) -> number,
  normalize: (v: vector) -> vector,
  cross: (a: vector, b: vector) -> vector,
  dot: (a: vector, b: vector) -> number,
  angle: (a: vector, b: vector, axis: vector?) -> number,
  floor: (v: vector) -> vector,
  ceil: (v: vector) -> vector,
  abs: (v: vector) -> vector,
  sign: (v: vector) -> vector,
  clamp: (v: vector, min: vector, max: vector) -> vector,
  max: (v: vector, ...vector) -> vector,
  min: (v: vector, ...vector) -> vector,
  lerp: (a: vector, b: vector, t: number) -> vector,
}

)BUILTIN_SRC";

static const char* const kBuiltinDefinitionUuidSrc = R"BUILTIN_SRC(

declare extern type uuid with
  istruthy: boolean
  bytes: string
  function __tostring(self): string
end

declare uuid: ((value: string? | buffer | uuid) -> uuid) & {
  create: (value: string? | buffer | uuid) -> uuid,
}

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
