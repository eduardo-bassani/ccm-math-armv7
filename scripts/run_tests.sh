#!/usr/bin/env bash

set -euo pipefail

# locate paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_ROOT/build"
INCLUDE_DIR="$PROJECT_ROOT/include"
SRC_DIR="$PROJECT_ROOT/src"
TEST_DIR="$PROJECT_ROOT/test"
RESULTS_FILE="$TEST_DIR/test_results.txt"

# 1) Prepare build directory
echo "Setting up build directory..."
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# 2) Compile everything into one testbench binary
echo "Compiling CCM sources and testbench..."
gcc -std=c99 -O0 \
    -I"$INCLUDE_DIR" \
    "$SRC_DIR/log.c" \
    "$SRC_DIR/exp.c" \
    "$SRC_DIR/sqrt.c" \
    "$SRC_DIR/cbrt.c" \
    "$TEST_DIR/testbench.c" \
    -lm -o "$BUILD_DIR/testbench"

# 3) Run the testbench, capture output
echo "Running testbench..."
mkdir -p "$TEST_DIR"
"$BUILD_DIR/testbench" > "$RESULTS_FILE"

echo "Results written to $RESULTS_FILE"

# 4) Clean up build artifacts
echo "Cleaning build directory..."
rm -rf "$BUILD_DIR"/*

echo "All done."
