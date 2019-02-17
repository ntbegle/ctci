#include <stdlib.h>
#include "ch3.h"
//#include "stack.h"
//#include "queue.h"


void min_push(MinStack* s, int val)
{
    MinStackNode* new_node = (MinStackNode*) malloc(sizeof(MinStackNode));
    new_node->val = val;
    new_node->next = s->head;

    if(s->head != NULL && s->head->min < val)
    {
        new_node->min = s->head->min;
    }
    else
    {
        new_node->min = val;
    }

    s->head = new_node;
}

int min_pop(MinStack* s)
{
    int val = s->head->val;
    MinStackNode* new_head = s->head->next;
    free(s->head);
    s->head = new_head;

    return val;
}

// Doesn't change the stack
int get_min(MinStack* s)
{
    return s->head->min;
}
