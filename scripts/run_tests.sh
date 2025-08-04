#!/usr/bin/env bash

set -euo pipefail

# Optimization level
LOG_OPT="-O0"
EXP_OPT="-O0"
SQRT_OPT="-O0"
CBRT_OPT="-O0"
TEST_OPT="-O0"

# locate paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_ROOT/build"
INCLUDE_DIR="$PROJECT_ROOT/include"
SRC_DIR="$PROJECT_ROOT/src"
TEST_DIR="$PROJECT_ROOT/test"
RESULTS_FILE="$TEST_DIR/test_results.txt"

# 1) Prepare build directory (preserve dir, clear contents)
echo "Setting up build directory..."
mkdir -p "$BUILD_DIR"
rm -rf "$BUILD_DIR"/*

# 2) Compile each module separately with its -Ox
echo "Compiling log2_non_optimized/log2_optimized..."
gcc -std=c99 $LOG_OPT -I"$INCLUDE_DIR" -c "$SRC_DIR/log.c" -o "$BUILD_DIR/log.o"

echo "Compiling exp2_non_optimized/exp2_optimized..."
gcc -std=c99 $EXP_OPT -I"$INCLUDE_DIR" -c "$SRC_DIR/exp.c" -o "$BUILD_DIR/exp.o"

echo "Compiling sqrt_non_optimized/sqrt_optimized..."
gcc -std=c99 $SQRT_OPT -I"$INCLUDE_DIR" -c "$SRC_DIR/sqrt.c" -o "$BUILD_DIR/sqrt.o"

echo "Compiling cbrt_non_optimized/cbrt_optimized..."
gcc -std=c99 $CBRT_OPT -I"$INCLUDE_DIR" -c "$SRC_DIR/cbrt.c" -o "$BUILD_DIR/cbrt.o"

echo "Compiling testbench..."
gcc -std=c99 $TEST_OPT -I"$INCLUDE_DIR" -c "$TEST_DIR/testbench.c" -o "$BUILD_DIR/testbench.o"

# 3) Link into testbench binary
echo "Linking testbench..."
gcc "$BUILD_DIR"/log.o "$BUILD_DIR"/exp.o "$BUILD_DIR"/sqrt.o "$BUILD_DIR"/cbrt.o "$BUILD_DIR"/testbench.o -lm -o "$BUILD_DIR/testbench"

# 4) Run and capture results
echo "Running testbench..."
mkdir -p "$TEST_DIR"
"$BUILD_DIR/testbench" > "$RESULTS_FILE"
echo "Results written to $RESULTS_FILE"

# 5) Clean up build artifacts (objects & exe, keep dir)
echo "Cleaning build directory contents..."
rm -f "$BUILD_DIR"/*.o "$BUILD_DIR"/testbench

echo "All done."
