
#ifndef STACK_H
#define STACK_H

typedef struct stack_node
{
    int val;
    struct stack_node* next;
} StackNode;

typedef struct stack
{
    StackNode* head;
} Stack;

void push(Stack* s, int val);

int pop(Stack* s);

#endif
