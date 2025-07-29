#pragma once

#include "q_formats.h"

/**
 * @brief Computes the square root of a normalized UQ4.28 fixed-point number.
 * 
 * @param M_norm Input number in UQ4.28 fixed-point format, where 1.0 ≤ M_norm < 4.0.
 * @return The square root of M_norm, also in UQ4.28 format.
 */
uq4_28_t sqrt_non_optimized(uq4_28_t M_norm);
uq4_28_t sqrt_optimized(uq4_28_t M_norm);
