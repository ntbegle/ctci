
#include <stdlib.h>
#include "queue.h"

void queue_init(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

void queue_add(Queue* q, void* val)
{
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));
    new_node->val = val;
    new_node->next = NULL;

    if(q->tail == NULL)
    {
        q->tail = new_node;
        q->head = new_node;
    }
    else
    {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void* queue_remove(Queue* q)
{
    if(q->head == NULL)
        return NULL;

    void* val = q->head->val;
    QueueNode* temp_node = q->head;
    q->head = q->head->next;
    free(temp_node);

    if(q->head == NULL)
    {
        q->tail = NULL;
    }

    return val;
}
