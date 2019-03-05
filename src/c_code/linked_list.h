
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct list_node
{
    void* val;
    struct list_node* next;
} ListNode;

typedef ListNode* ListIter;

typedef struct singly_list
{
    ListNode* head;
    ListNode* tail;
    int len;
} SinglyList;

void ll_push_back(SinglyList* l, void* val);
void ll_push_front(SinglyList* l, void* val);

ListNode* ll_find(SinglyList* l, void* val, bool (*compFuncPtr)(void*, void*));

void ll_init(SinglyList* l);

ListIter ll_init_iter(SinglyList* list);
ListIter ll_next_iter(ListIter iter);
#endif
