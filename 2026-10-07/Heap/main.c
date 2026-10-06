#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap.h"


int main() {
    srand((unsigned)(time(nullptr)));
    MinHeap *heap = heap_create(20);
    bool done = false;
    while (!done) {
        char command;
        int value;
        scanf(" %c", &command);
        switch (command) {
            case 'i':
            case 'I':
                scanf("%d", &value);
                heap_insert(heap, value);
                heap_print(heap);
                printf("\n");
                heap_draw(heap);
                break;
            case 'd':
            case 'D':
                value = heap_remove(heap);
                printf("Removed %d\n", value);
                heap_print(heap);
                printf("\n");
                heap_draw(heap);
                break;
            case 'p':
            case 'P':
                heap_print(heap);
                printf("\n");
                heap_draw(heap);
                break;
            case 'q':
            case 'Q':
                done = true;
                break;
            default:
                printf("Not a valid command\n");
                break;
        }
    }
    heap_dispose(heap);
}

