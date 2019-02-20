
#include <stdlib.h>
#include "linked_list.h"

void ll_init(SinglyList* l)
{
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
}

ListNode* init_list_node(void* val)
{
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void ll_push_back(SinglyList* l, void* val)
{
    ListNode* new_node = init_list_node(val);

    if(l->tail != NULL)
    {
        l->tail->next = new_node;
        l->tail = l->tail->next;
    }
    else
    {
        l->head = new_node;
        l->tail = new_node;
    }
    ++l->len;
}

ListNode* ll_find(SinglyList* l, void* val, bool (*compFuncPtr)(void*, void*))
{
    ListNode* cur_node = l->head;
    while(cur_node != NULL)
    {
        bool comp_result = (*compFuncPtr)(cur_node->val, val);
        if(comp_result)
        {
            return cur_node;
        }
        cur_node = cur_node->next;
    }

    return NULL;
}
