
#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node
{
    int val;
    struct queue_node next;
}QueueNode;

typedef struct queue
{
    QueueNode* head;
    QueueNode* tail;
} Queue;

void add(Queue* q, int val);

int remove(Queue* q);

#endif
