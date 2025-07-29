#pragma once

#include "q_formats.h"

/**
 * @brief Computes the cube root of a normalized UQ5.27 fixed-point number.
 * 
 * @param M_norm Input number in UQ5.27 fixed-point format, where 1.0 ≤ M_norm < 8.0.
 * @return The cube root of M_norm, also in UQ5.27 format.
 */
uq5_27_t cbrt_non_optimized(uq5_27_t M_norm);
uq5_27_t cbrt_optimized(uq5_27_t M_norm);
