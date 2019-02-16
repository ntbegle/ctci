
#include <stdio.h>
#include <stdlib.h>
#include "ch2.h"
#include "linked_list.h"

//1->2->5->1->2

void remove_dups(NODE* head)
{
    if(head == NULL)
        return;

    NODE* cur_node = head;
    while(cur_node != NULL)
    {
        NODE* other_node = cur_node;
        while(other_node != NULL && other_node->next != NULL)
        {
            if(cur_node->val == other_node->next->val)
            {
                printf("removing: %d\n", other_node->next->val);
                NODE* temp_node = other_node->next;
                other_node->next = other_node->next->next;
                free(temp_node);
            }
            else
            {
                other_node = other_node->next;
            }
        }
        cur_node = cur_node->next;
    }   
}


NODE* kth_last(NODE* head, int k)
{
    NODE* trail_node = head;

    while(head != NULL)
    {
        if(k == 0)
        {
            trail_node = trail_node->next;
        }
        else
        {
            --k;
        }
        head = head->next;
    }

    return trail_node;
}

void delete_mid(NODE* node_to_del)
{
    NODE* next_node = node_to_del->next;
    node_to_del->val = next_node->val;
    node_to_del->next = next_node->next;
    free(next_node);
}
