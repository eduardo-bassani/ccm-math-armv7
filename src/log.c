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
    register q2_30_t M = M_norm;
    register q2_30_t f = 0;
    register const q2_30_t *tab = log2_tab;
    register uint32_t mask = 0;

    register q2_30_t mu;
    register q2_30_t phi;
  
    for (int i = 0; i < Q2_30_FBITS; i += 3) {
        mu  = M + ((M + mask) >> i);
        phi = f - *tab++;
        if (mu <= Q2_30_ONE) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;

        mu  = M + ((M + mask) >> (i + 1));
        phi = f - *tab++;
        if (mu <= Q2_30_ONE) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;

        mu  = M + ((M + mask) >> (i + 2));
        phi = f - *tab++;
        if (mu <= Q2_30_ONE) {
            M = mu;
            f = phi;
        }
        mask = (mask << 1) | 1;
    }

   return f;
}
