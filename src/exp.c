#include "../include/q_formats.h"
#include "../include/log2_table.h"

q2_30_t exp2_non_optimized(q2_30_t M_norm) {
    q2_30_t M = M_norm;
    q2_30_t f = Q2_30_ONE;

    q2_30_t mu = M - log2_tab[0];
    q2_30_t phi = f + f;

    if (mu >= 0) {
        M = mu;
        f = phi;
    }

    for (int i = 1; i < Q2_30_FBITS; i++) {
        mu = M - log2_tab[i];
        phi = f + ((f + (1U << (i - 1))) >> i);

        if (mu >= 0) {
            M = mu;
            f = phi;
        }
    }

    return f;
}

q2_30_t exp2_optimized(q2_30_t M_norm) {
    register q2_30_t M = M_norm;
    register q2_30_t f = Q2_30_ONE;
    register const q2_30_t *tab = log2_tab;
    register uint32_t mask = 0;

    register q2_30_t mu;
    register q2_30_t phi;

    for (register int i = 0; i < Q2_30_FBITS; i += 3) {
        mu = M - *tab++;
        phi = f + ((f + mask) >> i);
        if (mu >= 0) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;

        mu = M - *tab++;
        phi = f + ((f + mask) >> (i + 1));
        if (mu >= 0) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;

        mu = M - *tab++;
        phi = f + ((f + mask) >> (i + 2));
        if (mu >= 0) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;
    }

    return f;
}
