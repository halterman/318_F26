#include <stdio.h>
#include <stdlib.h>
#include <time.h>

constexpr size_t MAX_NUMBER = 1'000'000'000;  // One billion

int main() {
    srand((unsigned)time(nullptr));
    int *counter = malloc(MAX_NUMBER * sizeof *counter);
    const size_t ITERATIONS = 3'000'000'000;
    // Compute frequencies
    puts("Computing frequencies");
    for (size_t i = 0; i < ITERATIONS; i++)
        counter[rand() % MAX_NUMBER]++;

    // Compute the mean for 0-147,483,647
    double sum1 = 0.0;
    for (size_t i = 0; i < 147'483'648; i++)
        sum1 += counter[i];
    double avg1 = sum1/147'483'648;

    // Compute the mean for 0-147,483,647
    double sum2 = 0.0;
    for (size_t i = 147'483'648; i < 1'000'000'000; i++)
        sum2 += counter[i];
    double avg2 = sum2/(1'000'000'000 - 147'483'648);

    printf("0-147,483,647 mean = %lf   147,483,648-1,000,000,000 = %lf\n", 
            avg1, avg2);
    printf("Ratio mean1 / mean2 = %lf\n", avg1/avg2);

    printf("Total mean = %lf\n", (sum1 + sum2)/1'000'000'000);
}
