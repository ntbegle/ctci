
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

#define MAX_NUM_ELEMENTS 32

void print_tree_node(BinaryTreeNode* node)
{
    printf("Visiting Node %d\n", node->val);
    if(node->left != NULL)
    {
        printf("  left  %d\n", node->left->val);
    }

    if(node->right != NULL)
    {
        printf("  right %d\n", node->right->val);
    }
}

int main(int argc, char** argv)
{
    int sorted_array_vals[MAX_NUM_ELEMENTS];
    int num_vals = argc - 1;

    for(int i = 1; i < argc; ++i)
    {
        sorted_array_vals[i-1] = atoi(argv[i]);
    }

    BinaryTree* bst = bt_create_minimal_bst(sorted_array_vals, num_vals);

    bt_visit_pre_order(bst, &print_tree_node);
}
