
#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node
{
    void* val;
    struct queue_node* next;
}QueueNode;

typedef struct queue
{
    QueueNode* head;
    QueueNode* tail;
} Queue;

void queue_init(Queue* q);
void queue_add(Queue* q, void* val);
void* queue_remove(Queue* q);

#endif
