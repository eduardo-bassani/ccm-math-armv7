#include "../include/q_formats.h"

uq5_27_t cbrt_non_optimized(uq5_27_t M_norm) {
    uq5_27_t f = UQ5_27_ONE;
    uq5_27_t f_cbrt = UQ5_27_ONE;

    uq5_27_t mu = f + f;
    mu = mu + mu;
    mu = mu + mu;
    uq5_27_t mu_cbrt = f_cbrt + f_cbrt;

    if (mu <= M_norm) {
        f = mu;
        f_cbrt = mu_cbrt;
    }

    for (int i = 1; i < UQ5_27_FBITS; i++) {
        uq5_27_t mu = f + ((f + (1U << (i - 1))) >> i);
        mu = mu + ((mu + (1U << (i - 1))) >> i);
        mu = mu + ((mu + (1U << (i - 1))) >> i);
        uq5_27_t mu_cbrt = f_cbrt + ((f_cbrt + (1U << (i - 1))) >> i);

        if (mu <= M_norm) {
            f = mu;
            f_cbrt = mu_cbrt;
        }
    }

    return f_cbrt;
}

uq5_27_t cbrt_optimized(uq5_27_t M_norm) {
    // Replace with actual optimized cube root function
    return cbrt_non_optimized(M_norm);
}
