#pragma once

#include <stdint.h>

/** Q2.30: signed, covers ≈[-2, +2) */
typedef int32_t  q2_30_t;
#define Q2_30_ONE ((q2_30_t)(1U << 30)) /* 1.0 in Q2.30 */
#define Q2_30_FBITS 30 /* fractional bits */

/** UQ4.28: unsigned, covers [0, 16) */
typedef uint32_t uq4_28_t;
#define UQ4_28_ONE ((uq4_28_t)(1U << 28)) /* 1.0 in UQ4.28 */
#define UQ4_28_FBITS 28

/** UQ5.27: unsigned, covers [0, 32) */
typedef uint32_t uq5_27_t;
#define UQ5_27_ONE ((uq5_27_t)(1U << 27)) /* 1.0 in UQ5.27 */
#define UQ5_27_FBITS 27
