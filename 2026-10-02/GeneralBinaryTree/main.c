#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binarytree.h"
#include "treeprinter.h"


int main() {
    srand((unsigned)(time(nullptr)));
    TreeNode *t = random_tree(10, 10'000);
    printf("Number of elements: %d  Height:  %d\n", size(t), height(t));
    draw_tree(t);
    printf("Preorder: ");
    preorder_print(t);
    printf("\n");
    printf("Inorder: ");
    inorder_print(t);
    printf("\n");
    dispose_tree(t);
}
