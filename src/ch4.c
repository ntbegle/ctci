
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
