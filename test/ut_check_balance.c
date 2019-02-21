
#include <stdio.h>
#include <stdlib.h>
#include "ch4.h"
#include "binary_tree.h"

#define MAX_NUM_ELEMENTS 32

void equal_sides_unbalanced(int* array_vals, int num_vals)
{
    BinaryTree* bt = bt_init_tree();

    bt->head = bt_init_node(array_vals[num_vals / 2]);
    BinaryTreeNode* cur_node = bt->head;
    for(int l = 0; l < num_vals / 2; ++l, cur_node = cur_node->left)
    {
        cur_node->left = bt_init_node(array_vals[l]);
    }

    cur_node = bt->head;
    for(int r = (num_vals / 2) + 1; r < num_vals; ++r, cur_node = cur_node->right)
    {
        cur_node->right = bt_init_node(array_vals[r]);
    }

    bool is_balanced = check_balance(bt);

    bt_free(bt);
    printf("Test case \"equal_sides_unbalanced\": is_balanced = %d\n", is_balanced);
}

void balanced_tree_test(int* array_vals, int num_vals)
{
    BinaryTree* bt = bt_create_minimal_bst(array_vals, num_vals);

    bool is_balanced = check_balance(bt);

    bt_free(bt);

    printf("Test case \"balanced_tree\": is_balanced = %d\n", is_balanced);
}

int main(int argc, char** argv)
{
    int sorted_array_vals[MAX_NUM_ELEMENTS];
    int num_vals = argc - 1;

    for(int i = 1; i < argc; ++i)
    {
        sorted_array_vals[i-1] = atoi(argv[i]);
    }

    balanced_tree_test(sorted_array_vals, num_vals);
    equal_sides_unbalanced(sorted_array_vals, num_vals);
}
