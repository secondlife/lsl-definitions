#!/usr/bin/env bash

set -ex

outdir="${1:-generated}"
mkdir -p "$outdir"

gen-lsl-definitions ./lsl_definitions.yaml syntax "$outdir/lsl_keywords.xml"
gen-lsl-definitions ./lsl_definitions.yaml slua_syntax ./slua_definitions.yaml "$outdir/slua_keywords.xml"
gen-lsl-definitions ./lsl_definitions.yaml slua_lsp_defs ./slua_definitions.yaml "$outdir/slua_default.d.luau"
gen-lsl-definitions ./lsl_definitions.yaml gen_builtins_txt "$outdir/builtins.txt"
