

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_node
{
    int val;
    struct binary_tree_node* left;
    struct binary_tree_node* right;
} BinaryTreeNode;

typedef struct binary_tree
{
    BinaryTreeNode* head;
} BinaryTree;

BinaryTreeNode* bt_init_node(int val);

BinaryTree* bt_init_tree();

void bt_visit_in_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*));

void bt_visit_pre_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*));

void bt_visit_post_order(BinaryTree* bt, void (*bt_visit)(BinaryTreeNode*));

BinaryTree* bt_create_minimal_bst(int* sorted_vals, int num_vals);

#endif
