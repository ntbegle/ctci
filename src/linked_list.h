
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_node
{
    int val;
    struct list_node* next;
} ListNode;

typedef struct singly_list
{
    ListNode* head;
    ListNode* tail;
} SinglyList;


#endif
