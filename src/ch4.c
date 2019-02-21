
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "ch4.h"

void list_of_depths_recurse(SinglyList* lists, BinaryTreeNode* btn, int level)
{
    if(btn == NULL)
        return;

    printf("Cur Level %d\n", level);
    ll_push_back(&lists[level], (void*) btn);
    list_of_depths_recurse(lists, btn->left, level+1);
    list_of_depths_recurse(lists, btn->right, level+1);
}

void list_of_depths(SinglyList* lists, BinaryTree* bt)
{
    if(bt == NULL || lists == NULL)
        return;
    
    list_of_depths_recurse(lists, bt->head, 0);
}

int check_balance_recurse(BinaryTreeNode* btn)
{
    if(btn == NULL)
        return 0;

    int num_nodes_left = check_balance_recurse(btn->left);
    int num_nodes_right = check_balance_recurse(btn->right);
    if(num_nodes_left < 0 || num_nodes_right < 0 || abs(num_nodes_left - num_nodes_right) > 1)
    {
        return -1;
    }
    
    return num_nodes_left + num_nodes_right + 1;
}

bool check_balance(BinaryTree* bt)
{
    if(bt == NULL)
        return true;

    return check_balance_recurse(bt->head) >= 0;
}

bool validate_bst_recurse(BinaryTreeNode* bstn, int* last)
{
    if(bstn == NULL)
        return true;

    if(!validate_bst_recurse(bstn->left, last))
    {
        return false;
    }

    if(bstn->val <= *last)
    {
        return false;
    }

    *last = bstn->val;

    if(!validate_bst_recurse(bstn->right, last))
    {
        return false;
    }        

    return true;
}

bool validate_bst(BinaryTree* bst)
{
    if(bst == NULL)
        return true;

    int last = INT_MIN;
    return validate_bst_recurse(bst->head, &last); 
}
