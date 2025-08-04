#include "../include/q_formats.h"

uq4_28_t sqrt_non_optimized(uq4_28_t M_norm) {
    uq4_28_t f = UQ4_28_ONE;
    uq4_28_t f_sqrt = UQ4_28_ONE;

    uq4_28_t mu = f + f;
    mu = mu + mu;
    uq4_28_t mu_sqrt = f_sqrt + f_sqrt;

    if (mu <= M_norm) {
        f = mu;
        f_sqrt = mu_sqrt;
    }

    for (int i = 1; i < UQ4_28_FBITS; i++) {
        uq4_28_t mu = f + ((f + (1U << (i - 1))) >> i);
        mu = mu + ((mu + (1U << (i - 1))) >> i);
        uq4_28_t mu_sqrt = f_sqrt + ((f_sqrt + (1U << (i - 1))) >> i);

        if (mu <= M_norm) {
            f = mu;
            f_sqrt = mu_sqrt;
        }
    }

    return f_sqrt;
}

uq4_28_t sqrt_optimized(uq4_28_t M_norm) {
    register uq4_28_t f = UQ4_28_ONE;
    register uq4_28_t f_sqrt = UQ4_28_ONE;
    register uint32_t mask = 1;
    register uint32_t j;

    register uq4_28_t mu = f + f;
    mu = mu + mu;
    register uq4_28_t mu_sqrt = f_sqrt + f_sqrt;

    if (mu <= M_norm) {
        f = mu;
        f_sqrt = mu_sqrt;
    }

    for (int i = 1; i < UQ4_28_FBITS; i += 3) {
        mu = f + ((f + mask) >> i);
        mu = mu + ((mu + mask) >> i);
        mu_sqrt = f_sqrt + ((f_sqrt + mask) >> i);
        if (mu <= M_norm) {
            f = mu;
            f_sqrt = mu_sqrt;
        }
        mask <<= 1;

        j = i + 1;

        mu = f + ((f + mask) >> j);
        mu = mu + ((mu + mask) >> j);
        mu_sqrt = f_sqrt + ((f_sqrt + mask) >> j);
        if (mu <= M_norm) {
            f = mu;
            f_sqrt = mu_sqrt;
        }
        mask <<= 1;

        j++;

        mu = f + ((f + mask) >> j);
        mu = mu + ((mu + mask) >> j);
        mu_sqrt = f_sqrt + ((f_sqrt + mask) >> j);
        if (mu <= M_norm) {
            f = mu;
            f_sqrt = mu_sqrt;
        }
        mask <<= 1;
    }

    return f_sqrt;
}
