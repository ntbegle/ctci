#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "ch3.h"

void print_stack(Stack* s)
{
    StackNode* cur_node = s->head;
    while(cur_node != NULL)
    {
        printf("%d ", cur_node->val);
        cur_node = cur_node->next;
    }
}

void print_stacks(SetOfStacks* sos)
{
    for(int i=0; i < MAX_STACKS; ++i)
    {
        printf("Stack %d: ", i);
        print_stack(sos->stacks[i]);
        printf("\n");
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    SetOfStacks stack;
    for(int i=0; i < MAX_STACKS; ++i)
    {
        stack.sizes[i] = 0;
        stack.stacks[i] = (Stack*)malloc(sizeof(Stack));
        stack.stacks[i]->head = NULL;
    }
    
    for(int i=1; i < argc; ++i)
    {
        printf("adding val %d to set of stacks\n", atoi(argv[i]));
        
        set_push(&stack, atoi(argv[i]));
    }

    print_stacks(&stack);

    int val = set_pop(&stack);
    while(val != -1)
    {
        printf("Pop: %d\n", val);
        val = set_pop(&stack);
    }
}
