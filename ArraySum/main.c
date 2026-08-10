#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "arraysum.h"

const char *arrtostr(const int *arr, int size) {
    static char buffer[256];  // Note: Local static string
    int offset = 0;
    offset += snprintf(buffer + offset, sizeof(buffer) - offset, "[");
    for (int i = 0; i < size; i++) {
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "%d", arr[i]);
        if (i < size - 1) {
            offset += snprintf(buffer + offset, sizeof(buffer) - offset, ", ");
        }
    }
    snprintf(buffer + offset, sizeof(buffer) - offset, "]");
    return buffer;
}

/**
 * Function to create an array of random integers
 * The caller is responsible for freeing the allocated memory.
 * The random numbers will be between 0 and max_value (inclusive).
 * The size parameter specifies the number of elements in the array.
 * The max_value parameter specifies the maximum value for the random numbers.
 * The function returns a pointer to the allocated array.
 */
int *make_random_array(int size, int max_value) {
    int *arr = malloc(size * sizeof(int));
    assert(arr);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value + 1); // Random numbers between 0 and max_value
    }
    return arr;
}

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator
    //int arr[] = { 1, 2, 3, 4, 5 };
    //int size = sizeof(arr) / sizeof(arr[0]);
    int *arr1 = make_random_array(10, 100);
    int *arr2 = make_random_array(10, 100);
    int sum1 = sum_array(arr1, 10);
    int sum2 = sum_array(arr2, 10);
    const char *s1 = arrtostr(arr1, 10);
    const char *s2 = arrtostr(arr2, 10);  // s1 and s2 share the same static local string  // !!!
    //printf("Sum of array: %s is %d\n", arrtostr(arr, 10), sum1);
    printf("Sum of array: %s is %d\n", s1, sum1);
    printf("Sum of array: %s is %d\n", s2, sum2);
    free(arr1);
    free(arr2);
}
