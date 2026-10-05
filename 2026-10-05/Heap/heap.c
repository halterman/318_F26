#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include "heap_common.h"
#include "drawheap.h"


// Creates an empty min-heap with a specified capacity.
MinHeap *heap_create(int capacity) {
    MinHeap *new_heap = malloc(sizeof *new_heap);
    assert(new_heap);
    new_heap->heap = malloc(capacity * sizeof *new_heap->heap);
    assert(new_heap->heap);
    new_heap->capacity = capacity;
    new_heap->size = 0;
    return new_heap;
}

// Frees up the memory held by the heap.
void heap_dispose(MinHeap *t) {
    free(t->heap);
    t->heap = nullptr;
    t->capacity = t->size = 0;
}

inline int left_child(int i) {
    return 2 * i + 1;
}

inline int right_child(int i) {
    return 2 * i + 2;
}

inline int parent(int i) {
    return (i - 1)/2;
}

static inline bool is_leaf(const MinHeap *h, int pos) {
    //return left_child(pos) >= h->size;
    return pos >= h->size/2 && pos < h->size;
}



// Inserts an item into the min-heap, if space exists.
// Returns true for a successful insertion and false if
// the heap is full.
bool heap_insert(MinHeap *heap, int item) {
    if (heap->size < heap->capacity) {
        int curr = heap->size++;
        heap->heap[curr] = item; // Start at end of heap
        // Now sift up until curr’s parent > curr
        while ((curr != 0) && (item < heap->heap[parent(curr)])) {
            heap->heap[curr] = heap->heap[parent(curr)];
            curr = parent(curr);
        }
        heap->heap[curr] = item; // Place new element;
        return true;
    }
    else
        return false;   // No room to insert item.
}


static void siftdown(MinHeap *heap, int pos) {
    int temp = heap->heap[pos];
    while (!is_leaf(heap, pos)) {  // Stop if pos is a leaf
        int j = left_child(pos), rc = right_child(pos);
        if ((rc < heap->size) && heap->heap[rc] < heap->heap[j])
            j = rc;       // Set j to greater child’s value
        if (temp < heap->heap[j]) 
            break;       // Done
        heap->heap[pos] = heap->heap[j];
        pos = j;          // Move down
    }
    heap->heap[pos] = temp;
}


static inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Removes and returns a least element from the min-heap, 
// if one exists.
// Result is undefined if the heap is empty.
int heap_remove(MinHeap *heap) {
    assert(heap->size > 0);
    swap(&heap->heap[0], &heap->heap[heap->size - 1]); // Swap first with last element
    heap->size--;
    if (heap->size != 0) 
        siftdown(heap, 0);    // Sift down new root element
    return heap->heap[heap->size];     // Return deleted value
}

// Prints the contents of a min-heap in linear fashion.
void heap_print(const MinHeap *heap) {
    printf("[");
    if (heap->size > 0) {
        printf("%d", heap->heap[0]);
        for (int i = 1; i < heap->size; i++) 
            printf(", %d", heap->heap[i]);
    }
    printf("]");
}

// Draws the min-heap as a binary tree.
void heap_draw(const MinHeap *heap) {
    draw_heap(heap);
}

