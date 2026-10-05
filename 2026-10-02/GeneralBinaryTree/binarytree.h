#ifndef BINARYTREE_H_
#define BINARYTREE_H_


// Represents a node in a binary tree of integers
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} TreeNode;


// Allocates a new binary tree node with the given
// integer data. The new node is a leaf with no
// children.
TreeNode *make_tree_node(int data);

// Builds a random binary tree of nodes with a maximum
// depth of n. The second parameter specifies the maximum
// data value in a node.
// Returns a pointer to the root of the tree.
TreeNode *random_tree(int n, int max_node_value);

//  Prints the preorder traversal of 
//  the binary tree to which t points.
void preorder_print(TreeNode *t);

//  Prints the inorder traversal of 
//  the binary tree to which t points.
void inorder_print(TreeNode *t);

// Returns the height of the tree to which
// t points. Height is the length of the longest 
// path from a leaf to the root.
int height(TreeNode *t);

// Returns the number of elements in the tree
// to which t points.  Returns 0 if t is nullptr.
int size(TreeNode *t);

// Frees up the memory held by the tree's nodes.
void dispose_tree(TreeNode *t);


#endif

