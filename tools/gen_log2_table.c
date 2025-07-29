#include <stdio.h>
#include <math.h>
#include "../include/q_formats.h"

int main(void) {
    printf("#pragma once\n");
    printf("#include \"q_formats.h\"\n\n");
    printf("static const q2_30_t log2_tab[%d] = {\n", Q2_30_FBITS);
    for (int i = 0; i < Q2_30_FBITS; i++) {
        double v = log2(1.0 + pow(2.0, -i));
        int32_t fixed = (int32_t)round(v * (1ULL << Q2_30_FBITS));
        printf("  0x%08x,%s", fixed, (i % 4 == 3) ? "\n" : " ");
    }
    printf("};\n");
    return 0;
}
