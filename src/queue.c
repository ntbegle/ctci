
#include "queue.h"

//1->2->3

void add(Queue* q, int val)
{
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));
    new_node->val = val;
    new_node->next = NULL;
    q->tail->next = new_node;
    q->tail = new_node;
}

int remove(Queue* q)
{
    int val = q->head->val;
    QueueNode* temp_node = q->head;
    q->head = q->head->next;
    free(temp_node);
    return val;
}
