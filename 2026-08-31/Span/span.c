#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "randrange.h"
#include "stopwatch.h"


int span1(const int *a, int n) {
    int min = a[0],
        max = min;
    for (int i = 1; i < n; i++) {
        if (min > a[i])
            min = a[i];
    }
    for (int i = 1; i < n; i++) {
        if (max < a[i])
            max = a[i];
    }
    return max - min;
}


int span2(const int *a, int n) {
    int min = a[0],
        max = min;
    for (int i = 1; i < n; i++) {
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }
    return max - min;
}

int s = 0;

// Document this function
static double time_it(const int *a, int n, int (*f)(const int *, int)) {
    struct stopwatch timer;

    sw_reset(&timer);
    sw_start(&timer);
    s = f(a, n);
    sw_stop(&timer);
    return sw_elapsed(&timer);
}

// Creates and returns an array holding n elements.
// Each each element is a random integer
// in the range 0...max_element - 1, inclusive.
// The caller is responsible to deallocate the 
// array's storage.
static int *make_array(int n, int max_element) {
    int *result = malloc(n * sizeof *result);
    assert(result != NULL);
    for (int i = 0; i < n; i++) {
        result[i] = randrange(0, max_element + 1);
    }
    return result;
}


// Print the contents of array a.
// Array a has size n.
//static void print_array(const int *a, int n) {
//    printf("{");
//    if (n > 0) {
//        printf("%d", a[0]);
//        for (int i = 1; i < n; i++) {
//            printf(", %d", a[i]);
//        }
//    }
//    printf("}");
//}

//static void test_make_array() {
//    for (int i = 0; i < 30; i++) {
//        print_array(make_array(20, 100), 20);
//        printf("\n");
//    }
//    printf("------------------\n");
//}


int main() {
    printf("    Size             span1           span2          Speedup \n");
    printf("-------------------------------------------------------------\n");
    for (int size = 50'000; size < 1'000'001; size += 50'000) {
        int *arr = make_array(size, 1'000'000'000);
        assert(arr != NULL);

		double t1 = time_it(arr, size, span1);
		double t2 = time_it(arr, size, span2);
		printf("%8d    ", size);
		printf("%15.6lf", t1);
		printf("%15.6lf", t2);
		printf("%15.1lf\n", t1 / t2);
        free(arr);
    }
    printf("%d\n", s);
}



