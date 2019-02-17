#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void push(Stack* s, int val)
{
    StackNode* new_node = (StackNode*) malloc(sizeof(StackNode));
    new_node->val = val;
    new_node->next = s->head;
    s->head = new_node;    
}

int pop(Stack* s)
{
    if(s->head == NULL)
    {
        return -1;
    }

    int val = s->head->val;
    StackNode* new_head = s->head->next;
    free(s->head);
    s->head = new_head;

    return val;
}

