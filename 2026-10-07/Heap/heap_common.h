#ifndef HEAP_COMMON_H_
#define HEAP_COMMON_H_

#include "heap.h"

// Represents a node in a binary minheap of integers
typedef struct minheap {
    int *heap;
    int capacity;
    int size;
} MinHeap;


// Returns the index of the root of the left subtree of index i.
int left_child(int i);

// Returns the index of the root of the right subtree of index i.
int right_child(int i);

// Returns the index of the parent of the entry at index i.
int parent(int i);


#endif

