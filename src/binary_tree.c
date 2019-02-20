
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BinaryTreeNode* bt_init_node(int val)
{
    BinaryTreeNode* new_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BinaryTree* bt_init_tree()
{
    BinaryTree* new_tree = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_tree->head = NULL;
    return new_tree;
}

void bt_in_order_traverse(BinaryTreeNode* btn, void (*bt_visit)(BinaryTreeNode*))
{
    if(btn == NULL)
        return;

    bt_in_order_traverse(btn->left, bt_visit);
    (*bt_visit)(btn);
    bt_in_order_traverse(btn->right, bt_visit);
}

void bt_pre_order_traverse(BinaryTreeNode* btn, void (*bt_visit)(BinaryTreeNode*))
{
    if(btn == NULL)
        return;

    (*bt_visit)(btn);
    bt_pre_order_traverse(btn->left, bt_visit);
    bt_pre_order_traverse(btn->right, bt_visit);
}

void bt_post_order_traverse(BinaryTreeNode* btn, void (*bt_visit)(BinaryTreeNode*))
{
    if(btn == NULL)
        return;

    bt_post_order_traverse(btn->left, bt_visit);
    bt_post_order_traverse(btn->right, bt_visit);
    (*bt_visit)(btn);
}

void bt_visit_in_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*))
{
    if(bt == NULL)
        return;
    bt_in_order_traverse(bt->head, bt_visit);
}

void bt_visit_pre_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*))
{
    if(bt == NULL)
        return;
    bt_pre_order_traverse(bt->head, bt_visit);
}

void bt_visit_post_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*))
{
    if(bt == NULL)
        return;
    bt_post_order_traverse(bt->head, bt_visit);
}

BinaryTreeNode* bt_create_minimal_bst_recurse(int* sorted_vals, int start_idx, int stop_idx)
{
    if(start_idx > stop_idx)
        return NULL;

    int mid_idx = start_idx + (stop_idx - start_idx) / 2;
    BinaryTreeNode* new_node = bt_init_node(sorted_vals[mid_idx]);
    new_node->left = bt_create_minimal_bst_recurse(sorted_vals, start_idx, mid_idx-1);
    new_node->right = bt_create_minimal_bst_recurse(sorted_vals, mid_idx+1, stop_idx);
    return new_node;
}

BinaryTree* bt_create_minimal_bst(int* sorted_vals, int num_vals)
{
    BinaryTree* bt = bt_init_tree();
    bt->head = bt_create_minimal_bst_recurse(sorted_vals, 0, num_vals - 1);
    return bt;
}
