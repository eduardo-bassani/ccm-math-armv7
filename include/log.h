#pragma once

#include "q_formats.h"

/**
 * @brief Computes the base-2 logarithm of a normalized Q2.30 fixed-point number.
 * 
 * @param M_norm Input number in Q2.30 fixed-point format, where 0.5 ≤ M_norm < 1.0.
 * @return The base-2 logarithm of M_norm, also in Q2.30 format.
 */
q2_30_t log2_non_optimized(q2_30_t M_norm);
q2_30_t log2_optimized(q2_30_t M_norm);
