#include <stdio.h>
#include <stdlib.h>
#include "ch3.h"


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


void set_push(SetOfStacks* sos, int val)
{   
    int stack_idx;
    for(stack_idx=0; stack_idx < MAX_STACKS; ++stack_idx)
    {
        if(sos->sizes[stack_idx] < MAX_STACK_SIZE)
        {
            break;
        }
    }

    if(stack_idx == MAX_STACKS)
    {
        printf("Max number of elements reached in stacks\n");
        return;
    }

    push(sos->stacks[stack_idx], val);
    ++sos->sizes[stack_idx];
}

int set_pop(SetOfStacks* sos)
{
    int stack_idx;
    for(stack_idx=0; stack_idx < MAX_STACKS; ++stack_idx)
    {
        if(sos->sizes[stack_idx] < MAX_STACK_SIZE)
        {
            break;
        }
    }

    if(stack_idx != 0 && (stack_idx == MAX_STACKS || sos->sizes[stack_idx] == 0))
    {
        --stack_idx;
    }

    --sos->sizes[stack_idx];

    return pop(sos->stacks[stack_idx]);
}
