#include "../include/q_formats.h"
#include "../include/log2_table.h"

q2_30_t log2_non_optimized(q2_30_t M_norm) {
    q2_30_t M = M_norm;
    q2_30_t f = 0;

    q2_30_t mu  = M + M;
    q2_30_t phi = f - log2_tab[0];
    
    if (mu <= Q2_30_ONE) {
        M = mu;
        f = phi;
    }

    for (int i = 1; i < Q2_30_FBITS; i++) {
        q2_30_t mu  = M + ((M + (1U << (i - 1))) >> i);
        q2_30_t phi = f - log2_tab[i];
        
        if (mu <= Q2_30_ONE) {
            M = mu;
            f = phi;
        }
    }

    return f;
}

q2_30_t log2_optimized(q2_30_t M_norm) {
    // Replace with actual optimized log2 function
    return log2_non_optimized(M_norm);
}
