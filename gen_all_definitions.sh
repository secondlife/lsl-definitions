#!/usr/bin/env bash

set -ex

outdir="${1:-generated}"
mkdir -p "$outdir" "$outdir/cpp" "$outdir/templated"

DEFS="./lsl_definitions.yaml"
SLUA="./slua_definitions.yaml"
CMD="python gen_definitions.py"

# Viewer outputs
$CMD $DEFS syntax "$outdir/lsl_keywords.xml"
$CMD $DEFS syntax --pretty "$outdir/lsl_keywords_pretty.xml"
$CMD $DEFS slua_syntax $SLUA "$outdir/slua_keywords.xml"
$CMD $DEFS slua_syntax --pretty $SLUA "$outdir/slua_keywords_pretty.xml"
$CMD $DEFS slua_lsp_defs $SLUA "$outdir/slua_default.d.luau"
$CMD $DEFS gen_builtins_txt "$outdir/builtins.txt"
$CMD $DEFS slua_selene $SLUA "$outdir/slua_selene.yml"

# C++ snippets
$CMD $DEFS gen_cpp_constants "$outdir/cpp/lllslconstants_generated.h"
$CMD $DEFS gen_lscript_library_defs "$outdir/cpp/lscript_library_defs.cpp"
$CMD $DEFS gen_lscript_interface "$outdir/cpp/lscript_interface.cpp"
$CMD $DEFS gen_mono_bind_interfaces "$outdir/cpp/mono_bind_interfaces.cpp"
$CMD $DEFS gen_lua_registrations 0 "$outdir/cpp/lua_registrations.cpp"
$CMD $DEFS gen_lua_constant_definitions "$outdir/cpp/lua_constant_definitions.cpp"
$CMD $DEFS gen_lscript_library_bind_pure "$outdir/cpp/lscript_library_bind_pure.cpp"
$CMD $DEFS gen_tree_header_file "$outdir/cpp/lscript_tree.h"
$CMD $DEFS gen_tree_source_file "$outdir/cpp/lscript_tree.cpp"

# Template-based
$CMD $DEFS gen_lexer_file ./templates/indra.in.l "$outdir/templated/indra.l"
$CMD $DEFS gen_parser_file ./templates/indra.in.y "$outdir/templated/indra.y"
$CMD $DEFS gen_mono_library_defs ./templates/LslLibrary.cs "$outdir/templated/LslLibrary.cs"
