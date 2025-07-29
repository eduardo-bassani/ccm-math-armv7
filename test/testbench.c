#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Include your custom header files
#include "../include/q_formats.h"
#include "../include/conversion.h"
#include "../include/log.h"
#include "../include/exp.h"
#include "../include/sqrt.h"
#include "../include/cbrt.h"

// --- Test Configuration ---
#define NUM_TIMING_RUNS 100000 // Number of runs for timing amortization

// --- Test Suites ---

void test_log2() {
    printf("\n--- Testing log2_non_optimized() vs log2_optimized() ---\n");
    printf("Input range: [0.5, 1.0), Format: Q2.30\n");

    const double test_inputs[] = {0.5, 0.6, 0.7, 0.8, 0.9, 0.999};
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start_std, end_std, start_opt, end_opt;
    double time_std = 0, time_opt = 0;
    double max_err_std = 0, max_err_opt = 0;
    double mae_std = 0, mae_opt = 0;
    double rmse_std = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = log2(input_val);
        q2_30_t input_q = double_to_q2_30(input_val);
        
        start_std = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile q2_30_t res = log2_non_optimized(input_q);
            (void)res;
        }
        end_std = clock();
        q2_30_t result_q_std = log2_non_optimized(input_q);
        double result_d_std = q2_30_to_double(result_q_std);
        double error_std = fabs(golden_val - result_d_std);

        start_opt = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile q2_30_t res = log2_optimized(input_q);
            (void)res;
        }
        end_opt = clock();
        q2_30_t result_q_opt = log2_optimized(input_q);
        double result_d_opt = q2_30_to_double(result_q_opt);
        double error_opt = fabs(golden_val - result_d_opt);

        time_std += ((double)(end_std - start_std)) / CLOCKS_PER_SEC;
        time_opt += ((double)(end_opt - start_opt)) / CLOCKS_PER_SEC;
        if (error_std > max_err_std) max_err_std = error_std;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_std += error_std;
        mae_opt += error_opt;
        rmse_std += error_std * error_std;
        rmse_opt += error_opt * error_opt;
    }

    mae_std /= num_inputs;
    mae_opt /= num_inputs;
    rmse_std = sqrt(rmse_std / num_inputs);
    rmse_opt = sqrt(rmse_opt / num_inputs);
    double avg_time_std = time_std / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\nStandard log2():\n");
    printf("  Avg. Time: %e s\n", avg_time_std);
    printf("  Max Error: %e\n", max_err_std);
    printf("  MAE      : %e\n", mae_std);
    printf("  RMSE     : %e\n", rmse_std);

    printf("\nOptimized log2_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt);
    printf("  RMSE     : %e\n", rmse_opt);

    if (avg_time_opt > 0) {
        printf("\nPerformance Speedup: %.2fx\n", avg_time_std / avg_time_opt);
    }
}

void test_exp2() {
    printf("\n--- Testing exp2_non_optimized() vs exp2_optimized() ---\n");
    printf("Input range: [0.0, 1.0), Format: Q2.30\n");

    const double test_inputs[] = {0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 0.999};
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start_std, end_std, start_opt, end_opt;
    double time_std = 0, time_opt = 0;
    double max_err_std = 0, max_err_opt = 0;
    double mae_std = 0, mae_opt = 0;
    double rmse_std = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = exp2(input_val);
        q2_30_t input_q = double_to_q2_30(input_val);
        
        start_std = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile q2_30_t res = exp2_non_optimized(input_q);
            (void)res;
        }
        end_std = clock();
        q2_30_t result_q_std = exp2_non_optimized(input_q);
        double result_d_std = q2_30_to_double(result_q_std);
        double error_std = fabs(golden_val - result_d_std);

        start_opt = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile q2_30_t res = exp2_optimized(input_q);
            (void)res;
        }
        end_opt = clock();
        q2_30_t result_q_opt = exp2_optimized(input_q);
        double result_d_opt = q2_30_to_double(result_q_opt);
        double error_opt = fabs(golden_val - result_d_opt);

        time_std += ((double)(end_std - start_std)) / CLOCKS_PER_SEC;
        time_opt += ((double)(end_opt - start_opt)) / CLOCKS_PER_SEC;
        if (error_std > max_err_std) max_err_std = error_std;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_std += error_std;
        mae_opt += error_opt;
        rmse_std += error_std * error_std;
        rmse_opt += error_opt * error_opt;
    }

    mae_std /= num_inputs;
    mae_opt /= num_inputs;
    rmse_std = sqrt(rmse_std / num_inputs);
    rmse_opt = sqrt(rmse_opt / num_inputs);
    double avg_time_std = time_std / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\nStandard exp2():\n");
    printf("  Avg. Time: %e s\n", avg_time_std);
    printf("  Max Error: %e\n", max_err_std);
    printf("  MAE      : %e\n", mae_std);
    printf("  RMSE     : %e\n", rmse_std);

    printf("\nOptimized exp2_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt);
    printf("  RMSE     : %e\n", rmse_opt);

    if (avg_time_opt > 0) {
        printf("\nPerformance Speedup: %.2fx\n", avg_time_std / avg_time_opt);
    }
}

void test_sqrt() {
    printf("\n--- Testing sqrt_non_optimized() vs sqrt_optimized() ---\n");
    printf("Input range: [1.0, 4.0), Format: UQ4.28\n");

    const double test_inputs[] = {1.0, 1.25, 1.5, 2.0, 2.75, 3.5, 3.999};
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start_std, end_std, start_opt, end_opt;
    double time_std = 0, time_opt = 0;
    double max_err_std = 0, max_err_opt = 0;
    double mae_std = 0, mae_opt = 0;
    double rmse_std = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = sqrt(input_val);
        uq4_28_t input_q = double_to_uq4_28(input_val);
        
        // --- Test Standard Function ---
        start_std = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile uq4_28_t res = sqrt_non_optimized(input_q); // volatile to prevent optimization
            (void)res; // Suppress unused variable warning
        }
        end_std = clock();
        
        uq4_28_t result_q_std = sqrt_non_optimized(input_q); // Get one result for error check
        double result_d_std = uq4_28_to_double(result_q_std);
        double error_std = fabs(golden_val - result_d_std);

        // --- Test Optimized Function ---
        start_opt = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile uq4_28_t res = sqrt_optimized(input_q);
            (void)res;
        }
        end_opt = clock();
        
        uq4_28_t result_q_opt = sqrt_optimized(input_q); // Get one result for error check
        double result_d_opt = uq4_28_to_double(result_q_opt);
        double error_opt = fabs(golden_val - result_d_opt);

        // Accumulate metrics
        time_std += ((double)(end_std - start_std)) / CLOCKS_PER_SEC;
        time_opt += ((double)(end_opt - start_opt)) / CLOCKS_PER_SEC;

        if (error_std > max_err_std) max_err_std = error_std;
        if (error_opt > max_err_opt) max_err_opt = error_opt;

        mae_std += error_std;
        mae_opt += error_opt;

        rmse_std += error_std * error_std;
        rmse_opt += error_opt * error_opt;
    }

    // Finalize and print results
    mae_std /= num_inputs;
    mae_opt /= num_inputs;
    rmse_std = sqrt(rmse_std / num_inputs);
    rmse_opt = sqrt(rmse_opt / num_inputs);
    double avg_time_std = time_std / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\nStandard sqrt():\n");
    printf("  Avg. Time: %e s\n", avg_time_std);
    printf("  Max Error: %e\n", max_err_std);
    printf("  MAE      : %e\n", mae_std);
    printf("  RMSE     : %e\n", rmse_std);

    printf("\nOptimized sqrt_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt);
    printf("  RMSE     : %e\n", rmse_opt);

    if (avg_time_opt > 0) {
        printf("\nPerformance Speedup: %.2fx\n", avg_time_std / avg_time_opt);
    }
}

void test_cbrt() {
    printf("\n--- Testing cbrt_non_optimized() vs cbrt_optimized() ---\n");
    printf("Input range: [1.0, 8.0), Format: UQ5.27\n");

    const double test_inputs[] = {1.0, 2.0, 3.0, 4.0, 5.5, 7.0, 7.999};
    const int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);

    clock_t start_std, end_std, start_opt, end_opt;
    double time_std = 0, time_opt = 0;
    double max_err_std = 0, max_err_opt = 0;
    double mae_std = 0, mae_opt = 0;
    double rmse_std = 0, rmse_opt = 0;

    for (int i = 0; i < num_inputs; i++) {
        double input_val = test_inputs[i];
        double golden_val = cbrt(input_val);
        uq5_27_t input_q = double_to_uq5_27(input_val);
        
        start_std = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile uq5_27_t res = cbrt_non_optimized(input_q);
            (void)res;
        }
        end_std = clock();
        uq5_27_t result_q_std = cbrt_non_optimized(input_q);
        double result_d_std = uq5_27_to_double(result_q_std);
        double error_std = fabs(golden_val - result_d_std);

        start_opt = clock();
        for(int j = 0; j < NUM_TIMING_RUNS; j++) {
            volatile uq5_27_t res = cbrt_optimized(input_q);
            (void)res;
        }
        end_opt = clock();
        uq5_27_t result_q_opt = cbrt_optimized(input_q);
        double result_d_opt = uq5_27_to_double(result_q_opt);
        double error_opt = fabs(golden_val - result_d_opt);

        time_std += ((double)(end_std - start_std)) / CLOCKS_PER_SEC;
        time_opt += ((double)(end_opt - start_opt)) / CLOCKS_PER_SEC;
        if (error_std > max_err_std) max_err_std = error_std;
        if (error_opt > max_err_opt) max_err_opt = error_opt;
        mae_std += error_std;
        mae_opt += error_opt;
        rmse_std += error_std * error_std;
        rmse_opt += error_opt * error_opt;
    }

    mae_std /= num_inputs;
    mae_opt /= num_inputs;
    rmse_std = sqrt(rmse_std / num_inputs);
    rmse_opt = sqrt(rmse_opt / num_inputs);
    double avg_time_std = time_std / (num_inputs * NUM_TIMING_RUNS);
    double avg_time_opt = time_opt / (num_inputs * NUM_TIMING_RUNS);

    printf("\nStandard cbrt():\n");
    printf("  Avg. Time: %e s\n", avg_time_std);
    printf("  Max Error: %e\n", max_err_std);
    printf("  MAE      : %e\n", mae_std);
    printf("  RMSE     : %e\n", rmse_std);

    printf("\nOptimized cbrt_optimized():\n");
    printf("  Avg. Time: %e s\n", avg_time_opt);
    printf("  Max Error: %e\n", max_err_opt);
    printf("  MAE      : %e\n", mae_opt);
    printf("  RMSE     : %e\n", rmse_opt);

    if (avg_time_opt > 0) {
        printf("\nPerformance Speedup: %.2fx\n", avg_time_std / avg_time_opt);
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
