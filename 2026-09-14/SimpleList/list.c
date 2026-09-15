#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *insert(Node *p, int n) {
    //  Check that we are not at the end of the list
    if (p)
        p->next = insert(p->next, n); // Add to rest of list
    else {   //  Insert new item
        p = malloc(sizeof *p);
        p->data = n;
        p->next = nullptr;
    }
    return p;
}


Node *insert2(Node *p, int n) {
    // Make the new node
    Node *nn = malloc(sizeof *nn);
    nn->data = n;
    nn->next = nullptr;
    // Find the last element in the list
    Node *cursor = p; 
    while (cursor && cursor->next) 
        cursor = cursor->next;
    if (cursor) {   // Insert on back of nonempty list
        cursor->next = nn;
    } else {
        p = nn; // List initially empty
    }
    return p;
}


void print_list(const Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node *head = nullptr;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    print_list(head);
        
}
