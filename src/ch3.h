
#ifndef CH3_H
#define CH3_H

//#include "queue.h"
//#include "stack.h"

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

#endif
