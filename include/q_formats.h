#pragma once

#include <stdint.h>

/** Q2.30: signed, covers ≈[-2, +2) */
typedef int32_t  q2_30_t;
#define Q2_30_ONE    ((q2_30_t)(1U << 30))  /* 1.0 in Q2.30 */
#define Q2_30_FBITS  30                     /* fractional bits */

/** Q3.29: signed, covers ≈[-4, +4) */
typedef int32_t  q3_29_t;
#define Q3_29_ONE    ((q3_29_t)(1U << 29))  /* 1.0 in Q3.29 */
#define Q3_29_FBITS  29

/** Q5.27: signed, covers ≈[-16, +16) */
typedef int32_t  q5_27_t;
#define Q5_27_ONE    ((q5_27_t)(1U << 27))  /* 1.0 in Q5.27 */
#define Q5_27_FBITS  27

/** UQ4.28: unsigned, covers [0, 16) */
typedef uint32_t uq4_28_t;
#define UQ4_28_ONE    ((uq4_28_t)(1U << 28)) /* 1.0 in UQ4.28 */
#define UQ4_28_FBITS  28

/** UQ5.27: unsigned, covers [0, 32) */
typedef uint32_t uq5_27_t;
#define UQ5_27_ONE    ((uq5_27_t)(1U << 27)) /* 1.0 in UQ5.27 */
#define UQ5_27_FBITS  27
