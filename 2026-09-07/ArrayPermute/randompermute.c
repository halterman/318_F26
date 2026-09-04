// RandomPermute.cpp
// Created 8/23/2018 10:18:47 PM

#include <stdio.h>

#include "randrange.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Randomly permute an array
void permute1(int *a, int n) {
    // Select a pseudorandom location from the current
    // location to the end of the collection
	for (int i = 0; i < n - 1; i++)
		swap(&a[i], &a[randrange(i, n)]);
}

// Randomly permute an array?
void permute2(int *a, int n) {
    // Select a pseudorandom position somewhere in the collection
	for (int i = 0; i < n; i++)
		swap(&a[i], &a[randrange(0, n)]);
}

// Classify an array as one of the six permutations.
// The array should have three elements.
int classify(const int *a) {
	switch (100 * a[0] + 10 * a[1] + a[2]) {
		case 123:  return 0;
		case 132:  return 1;
		case 213:  return 2;
		case 231:  return 3;
		case 312:  return 4;
		case 321:  return 5;
	}
	return -1;
}

// Report the accumulated statistics
// The array should have six elements.
void report(const int *a) {
	printf("1,2,3: %d\n", a[0]);
	printf("1,3,2: %d\n", a[1]);
	printf("2,1,3: %d\n", a[2]);
	printf("2,3,1: %d\n", a[3]);
	printf("3,1,2: %d\n", a[4]);
	printf("3,2,1: %d\n", a[5]);
}

// Fill the given array with zeros
void clear(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

// The destination array must be large enough to hold
// the elements of the source array.
void array_copy(int *desc, const int *src, int n) {
    for (int i = 0; i < n; i++)
        desc[i] = src[i];
}

int main() {
	int permutation_tally[] = {0, 0, 0, 0, 0, 0};  // Zero all counters

	// original always holds the array {1,2,3}
	const int original[] = {1, 2, 3};

	// working holds a copy of original is gets permuted and tallied
	int working[3];

	// Print the original vector

	// Run each permutation one hundred million times
	const int RUNS = 100'000'000;

	printf("--- Random permute #1 -----\n");
	clear(permutation_tally, 6);
	for (int i = 0; i < RUNS; i++) {  // Run 1,000,000 times
		// Make a copy of the original vector
		array_copy(working, original, 3);
		// Permute the vector with the first algorithm
		permute1(working, 3);
		// Count this permutation
		permutation_tally[classify(working)]++;
	}
	report(permutation_tally);   // Report results

	printf("--- Random permute #2 -----\n");
	clear(permutation_tally, 6);
	for (int i = 0; i < RUNS; i++) {  // Run 1,000,000 times
		// Make a copy of the original vector
		array_copy(working, original, 3);
		// Permute the vector with the second algorithm
		permute2(working, 3);
		// Count this permutation
		permutation_tally[classify(working)]++;
	}
	report(permutation_tally);   // Report results
}


