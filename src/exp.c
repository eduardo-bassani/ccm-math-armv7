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
    // Replace with actual optimized exp2 function
    return exp2_non_optimized(M_norm);
}
