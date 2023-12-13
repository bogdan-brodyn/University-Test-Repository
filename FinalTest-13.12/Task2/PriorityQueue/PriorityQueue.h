#pragma once

#include <stdlib.h>

typedef enum
{
    defaultErrorCode,
    memoryLack
} PriorityQueueErrorCode;

typedef struct PriorityQueue PriorityQueue;

PriorityQueueErrorCode enqueue(PriorityQueue** const queue,
    const int value, const int priority);

int dequeue(PriorityQueue* const queue);

void deletePriorityQueue(PriorityQueue** const queue);
