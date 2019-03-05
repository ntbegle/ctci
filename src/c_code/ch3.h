
#ifndef CH3_H
#define CH3_H

//#include "queue.h"
#include "stack.h"

// STACK MIN
typedef struct min_stack_node
{
    int val;
    int min;
    struct min_stack_node* next;
}MinStackNode;

typedef struct min_stack
{
    MinStackNode* head;
}MinStack;

void min_push(MinStack* s, int val);
int min_pop(MinStack* s);
int get_min(MinStack* s);
// END STACK MIN

// STACK OF PLATES
#define MAX_STACKS 3
#define MAX_STACK_SIZE 5
typedef struct set_of_stacks
{
    Stack* stacks[MAX_STACKS];
    int sizes[MAX_STACKS];
}SetOfStacks;

void set_push(SetOfStacks* sos, int val);
int set_pop(SetOfStacks* sos);
// END STACK OF PLATES

#endif
