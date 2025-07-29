#!/usr/bin/env bash
# scripts/gen_log2_table.sh
#
# Compile and run the log2 table generator to produce the lookup table header,

set -euo pipefail

# Determine directories relative to this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/../build"
SRC_TOOL="$SCRIPT_DIR/../tools/gen_log2_table.c"
GEN_TOOL="$BUILD_DIR/gen_log2_table"
OUT_HEADER="$SCRIPT_DIR/../include/log2_table.h"

# Ensure build directory exists
mkdir -p "$BUILD_DIR"

# Compile the generator into build directory
echo "Compiling generator: $SRC_TOOL -> $GEN_TOOL"
gcc -std=c99 -O2 "$SRC_TOOL" -lm -o "$GEN_TOOL"

# Run the generator to produce the header
echo "Generating header: $OUT_HEADER"
"$GEN_TOOL" > "$OUT_HEADER"

# Clean up the compiled generator
echo "Cleaning up generator binary"
rm -f "$GEN_TOOL"

echo "Done: $OUT_HEADER"
