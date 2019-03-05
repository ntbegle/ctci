#include <stdio.h>
#include <stdlib.h>
#include "ch3.h"

void print_stack(MinStack* s)
{
    MinStackNode* cur_node = s->head;
    printf("Stack: ");
    while(cur_node != NULL)
    {
        printf("%d ", cur_node->val);
        cur_node = cur_node->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    MinStack stack;
    stack.head = NULL;
    
    for(int i=1; i < argc; ++i)
    {
        printf("adding val %d to min stack\n", atoi(argv[i]));
        
        min_push(&stack, atoi(argv[i]));
    }

    while(stack.head != NULL)
    {
        print_stack(&stack);
        printf("Min: %d\n", get_min(&stack));
        printf("Removing: %d\n\n", min_pop(&stack));
    }
}
