
#include <stdio.h>
#include <stdlib.h>
#include "ch2.h"
#include "linked_list.h"

//1->2->5->1->2

void remove_dups(ListNode* head)
{
    if(head == NULL)
        return;

    ListNode* cur_node = head;
    while(cur_node != NULL)
    {
        ListNode* other_node = cur_node;
        while(other_node != NULL && other_node->next != NULL)
        {
            if(cur_node->val == other_node->next->val)
            {
                printf("removing: %d\n", other_node->next->val);
                ListNode* temp_node = other_node->next;
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


ListNode* kth_last(ListNode* head, int k)
{
    ListNode* trail_node = head;

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

void delete_mid(ListNode* node_to_del)
{
    ListNode* next_node = node_to_del->next;
    node_to_del->val = next_node->val;
    node_to_del->next = next_node->next;
    free(next_node);
}

