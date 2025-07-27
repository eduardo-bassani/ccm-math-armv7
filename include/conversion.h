#pragma once

#include "q_formats.h"
#include <stdint.h>

// Q2.30 conversions
static inline double q2_30_to_double(q2_30_t x) {
    return x / (double)(1ULL << Q2_30_FBITS);
}
static inline q2_30_t double_to_q2_30(double d) {
    return (q2_30_t)(d * (double)(1ULL << Q2_30_FBITS));
}

// Q3.29 conversions
static inline double q3_29_to_double(q3_29_t x) {
    return x / (double)(1ULL << Q3_29_FBITS);
}
static inline q3_29_t double_to_q3_29(double d) {
    return (q3_29_t)(d * (double)(1ULL << Q3_29_FBITS));
}

// Q5.27 conversions
static inline double q5_27_to_double(q5_27_t x) {
    return x / (double)(1ULL << Q5_27_FBITS);
}
static inline q5_27_t double_to_q5_27(double d) {
    return (q5_27_t)(d * (double)(1ULL << Q5_27_FBITS));
}

// UQ4.28 conversions
static inline double uq4_28_to_double(uq4_28_t x) {
    return x / (double)(1ULL << UQ4_28_FBITS);
}
static inline uq4_28_t double_to_uq4_28(double d) {
    return (uq4_28_t)(d * (double)(1ULL << UQ4_28_FBITS));
}

// UQ5.27 conversions
static inline double uq5_27_to_double(uq5_27_t x) {
    return x / (double)(1ULL << UQ5_27_FBITS);
}
static inline uq5_27_t double_to_uq5_27(double d) {
    return (uq5_27_t)(d * (double)(1ULL << UQ5_27_FBITS));
}
