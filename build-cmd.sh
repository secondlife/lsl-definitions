#!/usr/bin/env bash

cd "$(dirname "$0")"
top="$(pwd)"

# turn on verbose debugging output for parabuild logs.
exec 4>&1; export BASH_XTRACEFD=4; set -x
# make errors fatal
set -e
# complain about unset env variables
set -u

if [ -z "$AUTOBUILD" ] ; then
   exit 1
fi

if [ "$OSTYPE" = "cygwin" ] ; then
   autobuild="$(cygpath -u "$AUTOBUILD")"
else
   autobuild="$AUTOBUILD"
fi

stage="$(pwd)/stage"
mkdir -p "$stage"
mkdir -p "$stage/LICENSES"

# load autobuild provided shell functions and variables
source_environment_tempfile="$stage/source_environment.sh"
"$autobuild" source_environment > "$source_environment_tempfile"
. "$source_environment_tempfile"

# Generate definition files
./gen_all_definitions.sh "$stage/lsl_definitions"

# Copy source files
cp lsl_definitions.yaml "$stage/lsl_definitions/"
cp slua_definitions.yaml "$stage/lsl_definitions/"
cp gen_definitions.py "$stage/lsl_definitions/"
cp LICENSE "$stage/LICENSES/lsl_definitions.txt"
