# High-Performance Math Functions for ARMv7 using CCM

This project provides a collection of optimized, fixed-point mathematical functions for ARMv7-A embedded processors, specifically designed for systems without a Floating-Point Unit (FPU). By implementing the **Convergence Computing Method (CCM)**, these functions offer a high-performance alternative to standard C math libraries for complex operations.

## About The Project

In many embedded systems, cost and power constraints lead to the use of processors without a dedicated FPU. Standard mathematical functions (`log`, `exp`, `sqrt`) rely on slow software emulation in these environments, creating performance bottlenecks.

This project tackles that challenge by using the Convergence Computing Method, an iterative approach that calculates complex functions using only fast, hardware-native operations like addition, subtraction, and bit-shifting.

The project implements the following four functions:

* `log2`: Base-2 Logarithm
* `exp2`: Base-2 Exponential
* `sqrt`: Square Root
* `cbrt`: Cubic Root

The work focuses on both manual C-code optimizations and analysis of compiler-generated assembly to achieve speedups while maintaining precision.

## Key Features

* **FPU-Free Calculation**: Designed from the ground up to run efficiently on simple, FPU-less hardware.
* **Fixed-Point Arithmetic**: Uses 32-bit fixed-point data representation (Q2.30, UQ4.28, UQ5.27) to balance range and precision.
* **Optimized for ARMv7-A**: Leverages manual C optimizations (register hints, pointer arithmetic, loop unrolling) and compiler knowledge of the ARM architecture.
* **High Performance**: Achieves significant speedups over standard C library functions (up to **3.35x** for `exp2` and **3.10x** for `cbrt`).
* **High Accuracy**: Maintains excellent precision, with errors on the order of 10⁻⁸ to 10⁻⁹.

## Project Structure

The repository is organized to separate the core functions, public headers, scripts, and testing utilities.

* **`/include`**: Contains header files, including fixed-point data type definitions and lookup tables.
* **`/src`**: Contains the C source code for the core mathematical functions. Each file includes both a non-optimized and an optimized version.
* **`/test`**: Holds the testbench used to benchmark performance and validate the accuracy of the functions against the standard C math library.
* **`/scripts`**: Contains shell scripts for automating tasks like building the project and running tests.
* **`/tools`**: Includes helper utilities, such as scripts to generate pre-computed tables.
* **`/doc`**: Includes a detailed project documentation, the report.

## Environment & Toolchain

This project was developed and tested in a specific environment to ensure consistent and reliable results.

* **Target Architecture**: 32-bit ARMv7-A
* **Operating System**: Fedora 29 Linux (Kernel 4.18.16)
* **Virtualization**: QEMU (via UTM on macOS)
* **Compiler**: GCC (GNU Compiler Collection) version 8.2.1
