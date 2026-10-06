#ifndef HEAP_H_
#define HEAP_H_

// Forward reference
typedef struct minheap MinHeap;  // Convenient type alias


// Creates a pointer to an empty min-heap with a specified capacity.
MinHeap *heap_create(int capacity);

// Frees up the memory held by the heap.
void heap_dispose(MinHeap *t);

// Inserts an item into the min-heap, if space exists.
// Returns true for a successful insertion and false if
// the heap is full.
bool heap_insert(MinHeap *heap, int item);

// Removes a least element from the min-heap, if one exists.
// Result is undefined if the heap is empty.
int heap_remove(MinHeap *heap);

// Returns true for a successful removal and false if
// the heap is empty.
int heap_remove(MinHeap *heap);

// Prints the contents of a min-heap in linear fashion.
void heap_print(const MinHeap *heap);

// Draws the min-heap as a binary tree.
void heap_draw(const MinHeap *heap);

// Returns the index of the root of the left subtree of index i.
int left_child(int i);

// Returns the index of the root of the right subtree of index i.
int right_child(int i);

// Returns the index of the parent of the entry at index i.
int parent(int i);


#endif

