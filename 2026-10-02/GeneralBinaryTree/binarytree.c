#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binarytree.h"

inline static int max(int a, int b) {
    return (a > b) ? a : b;
}

// Allocates a new binary tree node with the given
// integer data. The new node is a leaf with no
// children.
TreeNode *make_tree_node(int data) {
    TreeNode *result = malloc(sizeof *result);
    result->data = data;
    result->left = result->right = nullptr;
    return result;
}


// Builds a random binary tree of nodes with a maximum
// depth of n. The second parameter specifies the maximum
// data value in a node.
// Returns a pointer to the root of the tree.
TreeNode *random_tree(int n, int max_node_value) {
    TreeNode *root = nullptr;
    if (n > 0) {
        root = make_tree_node(rand() % max_node_value);
        root->left = random_tree(rand() % n, max_node_value);
        root->right = random_tree(rand() % n, max_node_value);
    }
    return root;
}


//  Prints the preorder traversal of 
//  the binary tree to which t points.
void preorder_print(TreeNode *t) {
    if (t) {
        printf("%d ", t->data);
        preorder_print(t->left);
        preorder_print(t->right);
    }
}


//  Prints the inorder traversal of 
//  the binary tree to which t points.
void inorder_print(struct node *t) {
    if (t) {
        inorder_print(t->left);
        printf("%d ", t->data);
        inorder_print(t->right);
    }
}


// Returns the height of the tree to which
// t points. Height is the length of the longest 
// path from a leaf to the root.
int height(TreeNode *t) {
    if (t) 
        return 1 + max(height(t->left), height(t->right));
    else
        return -1;
}

// Returns the number of elements in the tree
// to which t points.  Returns 0 if t is nullptr.
int size(TreeNode *t) {
    if (t) 
        return 1 + size(t->left) + size(t->right);
    else
        return 0;
}

// Frees up the memory held by the tree's nodes.
void dispose_tree(TreeNode *t) {
    // Same as the BST assignment dispose code.
}

