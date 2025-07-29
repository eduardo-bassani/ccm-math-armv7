#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "q_formats.h"
#include "conversion.h"
#include "log.h"
#include "exp.h"
#include "sqrt.h"
#include "cbrt.h"

#define NUM_TIMING_RUNS 100000 // Number of runs for timing amortization

void test_log2() {
    printf("\n--- Testing log2() Implementations ---\n");
    printf("Input Format: Q2.30 for custom, double for C standard\n");

    const double test_inputs[] = {
        0.5, 0.5123, 0.5678, 0.6234, 0.6789, 0.7345, 0.7891, 0.8456,
        0.8912, 0.9123, 0.9345, 0.9567, 0.9789, 0.9899, 0.9955, 0.999999
    };
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start;
    double time_c_lib = 0, time_non_opt = 0, time_opt = 0;
    double max_err_non_opt = 0, max_err_opt = 0;
    double mae_non_opt = 0, mae_opt = 0;
    double rmse_non_opt = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = log2(input_val);
        q2_30_t input_q = double_to_q2_30(input_val);

        // 1. Test Standard C Library Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile double res = log2(input_val); (void)res; }
        time_c_lib += ((double)(clock() - start)) / CLOCKS_PER_SEC;

        // 2. Test Non-Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile q2_30_t res = log2_non_optimized(input_q); (void)res; }
        time_non_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_non_opt = q2_30_to_double(log2_non_optimized(input_q));
        double error_non_opt = fabs(golden_val - result_d_non_opt);

        // 3. Test Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile q2_30_t res = log2_optimized(input_q); (void)res; }
        time_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_opt = q2_30_to_double(log2_optimized(input_q));
        double error_opt = fabs(golden_val - result_d_opt);

        // Accumulate error metrics
        if (error_non_opt > max_err_non_opt) max_err_non_opt = error_non_opt;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_non_opt += error_non_opt; mae_opt += error_opt;
        rmse_non_opt += error_non_opt * error_non_opt; rmse_opt += error_opt * error_opt;
    }

    // Finalize and print results
    double avg_time_c_lib = time_c_lib / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_non_opt = time_non_opt / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\n1. Standard C log2() (double):\n");
    printf("  Avg. Time: %e s\n", avg_time_c_lib);
    
    printf("\n2. Custom Fixed-Point log2_non_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_non_opt);
    printf("  Max Error: %e\n", max_err_non_opt);
    printf("  MAE      : %e\n", mae_non_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_non_opt / num_inputs));

    printf("\n3. Custom Fixed-Point log2_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_opt / num_inputs));

    printf("\n--- Performance Analysis ---\n");
    if (avg_time_opt > 0) printf("  Optimized vs. Non-Optimized: %.2fx speedup\n", avg_time_non_opt / avg_time_opt);
    if (avg_time_c_lib > 0) {
        printf("  Non-Optimized vs. C Library: %.2fx speedup\n", avg_time_c_lib / avg_time_non_opt);
        printf("  Optimized vs. C Library:     %.2fx speedup\n", avg_time_c_lib / avg_time_opt);
    }
}

void test_exp2() {
    printf("\n--- Testing exp2() Implementations ---\n");
    printf("Input Format: Q2.30 for custom, double for C standard\n");

    const double test_inputs[] = {
        0.0, 0.0123, 0.0678, 0.1234, 0.2345, 0.3456, 0.4567, 0.5678,
        0.6789, 0.7891, 0.8912, 0.9123, 0.9567, 0.9789, 0.9899, 0.999999
    };
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start;
    double time_c_lib = 0, time_non_opt = 0, time_opt = 0;
    double max_err_non_opt = 0, max_err_opt = 0;
    double mae_non_opt = 0, mae_opt = 0;
    double rmse_non_opt = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = exp2(input_val);
        q2_30_t input_q = double_to_q2_30(input_val);

        // 1. Test Standard C Library Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile double res = exp2(input_val); (void)res; }
        time_c_lib += ((double)(clock() - start)) / CLOCKS_PER_SEC;

        // 2. Test Non-Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile q2_30_t res = exp2_non_optimized(input_q); (void)res; }
        time_non_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double error_non_opt = fabs(golden_val - q2_30_to_double(exp2_non_optimized(input_q)));

        // 3. Test Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile q2_30_t res = exp2_optimized(input_q); (void)res; }
        time_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double error_opt = fabs(golden_val - q2_30_to_double(exp2_optimized(input_q)));

        // Accumulate error metrics
        if (error_non_opt > max_err_non_opt) max_err_non_opt = error_non_opt;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_non_opt += error_non_opt; mae_opt += error_opt;
        rmse_non_opt += error_non_opt * error_non_opt; rmse_opt += error_opt * error_opt;
    }
    
    // Finalize and print results
    double avg_time_c_lib = time_c_lib / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_non_opt = time_non_opt / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\n1. Standard C exp2() (double):\n");
    printf("  Avg. Time: %e s\n", avg_time_c_lib);
    printf("\n2. Custom Fixed-Point exp2_non_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_non_opt);
    printf("  Max Error: %e\n", max_err_non_opt);
    printf("  MAE      : %e\n", mae_non_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_non_opt / num_inputs));
    printf("\n3. Custom Fixed-Point exp2_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_opt / num_inputs));

    printf("\n--- Performance Analysis ---\n");
    if (avg_time_opt > 0) printf("  Optimized vs. Non-Optimized: %.2fx speedup\n", avg_time_non_opt / avg_time_opt);
    if (avg_time_c_lib > 0) {
        printf("  Non-Optimized vs. C Library: %.2fx speedup\n", avg_time_c_lib / avg_time_non_opt);
        printf("  Optimized vs. C Library:     %.2fx speedup\n", avg_time_c_lib / avg_time_opt);
    }
}

void test_sqrt() {
    printf("\n--- Testing sqrt() Implementations ---\n");
    printf("Input Format: UQ4.28 for custom, double for C standard\n");

    const double test_inputs[] = {
        1.0, 1.1234, 1.3456, 1.5678, 1.7891, 2.1234, 2.3456, 2.5678,
        2.7891, 3.1234, 3.3456, 3.5678, 3.7891, 3.8999, 3.9555, 3.999999
    };
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start;
    double time_c_lib = 0, time_non_opt = 0, time_opt = 0;
    double max_err_non_opt = 0, max_err_opt = 0;
    double mae_non_opt = 0, mae_opt = 0;
    double rmse_non_opt = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = sqrt(input_val);
        uq4_28_t input_q = double_to_uq4_28(input_val);
        
        // 1. Test Standard C Library Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile double res = sqrt(input_val); (void)res; }
        time_c_lib += ((double)(clock() - start)) / CLOCKS_PER_SEC;

        // 2. Test Non-Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile uq4_28_t res = sqrt_non_optimized(input_q); (void)res; }
        time_non_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_non_opt = uq4_28_to_double(sqrt_non_optimized(input_q));
        double error_non_opt = fabs(golden_val - result_d_non_opt);

        // 3. Test Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile uq4_28_t res = sqrt_optimized(input_q); (void)res; }
        time_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_opt = uq4_28_to_double(sqrt_optimized(input_q));
        double error_opt = fabs(golden_val - result_d_opt);

        // Accumulate error metrics
        if (error_non_opt > max_err_non_opt) max_err_non_opt = error_non_opt;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_non_opt += error_non_opt; mae_opt += error_opt;
        rmse_non_opt += error_non_opt * error_non_opt; rmse_opt += error_opt * error_opt;
    }

    // Finalize and print results
    double avg_time_c_lib = time_c_lib / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_non_opt = time_non_opt / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\n1. Standard C sqrt() (double):\n");
    printf("  Avg. Time: %e s\n", avg_time_c_lib);
    printf("\n2. Custom Fixed-Point sqrt_non_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_non_opt);
    printf("  Max Error: %e\n", max_err_non_opt);
    printf("  MAE      : %e\n", mae_non_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_non_opt / num_inputs));
    printf("\n3. Custom Fixed-Point sqrt_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_opt / num_inputs));

    printf("\n--- Performance Analysis ---\n");
    if (avg_time_opt > 0) printf("  Optimized vs. Non-Optimized: %.2fx speedup\n", avg_time_non_opt / avg_time_opt);
    if (avg_time_c_lib > 0) {
        printf("  Non-Optimized vs. C Library: %.2fx speedup\n", avg_time_c_lib / avg_time_non_opt);
        printf("  Optimized vs. C Library:     %.2fx speedup\n", avg_time_c_lib / avg_time_opt);
    }
}

void test_cbrt() {
    printf("\n--- Testing cbrt() Implementations ---\n");
    printf("Input Format: UQ5.27 for custom, double for C standard\n");

    const double test_inputs[] = {
        1.0, 1.2345, 1.6789, 2.1234, 2.5678, 3.4567, 3.8912, 4.3456,
        4.7891, 5.2345, 5.6789, 6.1234, 6.5678, 7.1234, 7.5678, 7.999999
    };
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start;
    double time_c_lib = 0, time_non_opt = 0, time_opt = 0;
    double max_err_non_opt = 0, max_err_opt = 0;
    double mae_non_opt = 0, mae_opt = 0;
    double rmse_non_opt = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = cbrt(input_val);
        uq5_27_t input_q = double_to_uq5_27(input_val);
        
        // 1. Test Standard C Library Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile double res = cbrt(input_val); (void)res; }
        time_c_lib += ((double)(clock() - start)) / CLOCKS_PER_SEC;

        // 2. Test Non-Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile uq5_27_t res = cbrt_non_optimized(input_q); (void)res; }
        time_non_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_non_opt = uq5_27_to_double(cbrt_non_optimized(input_q));
        double error_non_opt = fabs(golden_val - result_d_non_opt);

        // 3. Test Optimized Custom Function
        start = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) { volatile uq5_27_t res = cbrt_optimized(input_q); (void)res; }
        time_opt += ((double)(clock() - start)) / CLOCKS_PER_SEC;
        double result_d_opt = uq5_27_to_double(cbrt_optimized(input_q));
        double error_opt = fabs(golden_val - result_d_opt);

        // Accumulate error metrics
        if (error_non_opt > max_err_non_opt) max_err_non_opt = error_non_opt;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_non_opt += error_non_opt; mae_opt += error_opt;
        rmse_non_opt += error_non_opt * error_non_opt; rmse_opt += error_opt * error_opt;
    }

    // Finalize and print results
    double avg_time_c_lib = time_c_lib / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_non_opt = time_non_opt / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\n1. Standard C cbrt() (double):\n");
    printf("  Avg. Time: %e s\n", avg_time_c_lib);
    printf("\n2. Custom Fixed-Point cbrt_non_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_non_opt);
    printf("  Max Error: %e\n", max_err_non_opt);
    printf("  MAE      : %e\n", mae_non_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_non_opt / num_inputs));
    printf("\n3. Custom Fixed-Point cbrt_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt / num_inputs);
    printf("  RMSE     : %e\n", sqrt(rmse_opt / num_inputs));
    
    printf("\n--- Performance Analysis ---\n");
    if (avg_time_opt > 0) printf("  Optimized vs. Non-Optimized: %.2fx speedup\n", avg_time_non_opt / avg_time_opt);
    if (avg_time_c_lib > 0) {
        printf("  Non-Optimized vs. C Library: %.2fx speedup\n", avg_time_c_lib / avg_time_non_opt);
        printf("  Optimized vs. C Library:     %.2fx speedup\n", avg_time_c_lib / avg_time_opt);
    }
}

int main() {
    printf("============================================\n");
    printf("= Fixed-Point Math Function Testbench      =\n");
    printf("= Timing runs per input: %d           =\n", NUM_TIMING_RUNS);
    printf("============================================\n");

    test_log2();
    printf("--------------------------------------------\n");
    test_exp2();
    printf("--------------------------------------------\n");
    test_sqrt();
    printf("--------------------------------------------\n");
    test_cbrt();
    printf("--------------------------------------------\n");

    printf("\nTestbench finished.\n");

    return 0;
}
