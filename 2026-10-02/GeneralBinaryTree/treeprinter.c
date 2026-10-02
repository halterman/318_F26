// Liberally adapted from 
// https://www.techiedelight.com/c-program-print-binary-tree/

#include <stdio.h>
#include <stdlib.h>
#include "treeprinter.h"

static constexpr int HORIZONTAL_LINE = 0;
//static constexpr int VERTICAL_LINE   = 1;
static constexpr int RIGHT_BRANCH    = 2;
static constexpr int LEFT_BRANCH     = 3;
static constexpr int CONNECTOR       = 4;
static constexpr int SPACER          = 5;

static const char *connectors[] = {
    "--",
    "|",
    ".--",
    "`--",
    "     |",
    "      "
};


struct trunk {
    struct trunk *prev;
    int connector_index;
};

struct trunk *make_trunk(struct trunk *prev, int n) {
    struct trunk *result = malloc(sizeof *result);
    result->prev = prev;
    result->connector_index = n;
    return result;
}


 
// Helper function to print branches of the binary tree
static void show_trunks(struct trunk *p) {
    if (p) {
        show_trunks(p->prev);
        printf("%s", connectors[p->connector_index]);
    }
}


void draw_tree_helper(TreeNode *root, struct trunk *prev, bool is_left) {
    if (root) {
        int prev_connector = SPACER; 
        struct trunk *trunk = make_trunk(prev, prev_connector);
        draw_tree_helper(root->right, trunk, true);
        if (!prev) {
            trunk->connector_index = HORIZONTAL_LINE;
        } else if (is_left) {
            trunk->connector_index = RIGHT_BRANCH;
            prev_connector = CONNECTOR;
        } else {
            trunk->connector_index = LEFT_BRANCH;
            prev->connector_index = prev_connector;
        }
        show_trunks(trunk);
        printf(" %d\n", root->data);
        if (prev) {
            prev->connector_index = prev_connector;
        }
        trunk->connector_index = CONNECTOR;
        draw_tree_helper(root->left, trunk, false);
        free(trunk);
    }
}

void draw_tree(TreeNode *root) {
    draw_tree_helper(root, nullptr, false);
}

