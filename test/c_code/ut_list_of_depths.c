
#include <stdio.h>
#include <stdlib.h>
#include "ch4.h"
#include "linked_list.h"
#include "binary_tree.h"

#define MAX_NUM_ELEMENTS 32

int main(int argc, char** argv)
{
    int sorted_array_vals[MAX_NUM_ELEMENTS];
    int num_vals = argc - 1;

    for(int i = 1; i < argc; ++i)
    {
        sorted_array_vals[i-1] = atoi(argv[i]);
    }

    BinaryTree* bst = bt_create_minimal_bst(sorted_array_vals, num_vals);

    SinglyList* lists = (SinglyList*) malloc(sizeof(SinglyList) * num_vals);
    for(int i = 0; i < num_vals; ++i)
    {
        ll_init(&lists[i]);
    }

    list_of_depths(lists, bst);

    int depth = 0;
    while(lists[depth].len != 0)
    {
        printf("Values at depth %d: ", depth);
        ListNode* cur_node = lists[depth].head;
        while(cur_node != NULL)
        {
            BinaryTreeNode* btn = (BinaryTreeNode*) cur_node->val;
            printf("%d ", btn->val);
            cur_node = cur_node->next;
        }
        printf("\n");

        ++depth;
    }
}
