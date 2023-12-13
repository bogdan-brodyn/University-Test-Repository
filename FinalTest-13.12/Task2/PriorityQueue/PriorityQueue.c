#include "PriorityQueue.h"

typedef struct QueueElement
{
    int value;
    int priority;
} QueueElement;

struct PriorityQueue
{
    size_t size;
    size_t capasity;
    QueueElement* list;
};

static PriorityQueue* createQueue(void)
{
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->size = 0;
    queue->capasity = 1;
    queue->list = (QueueElement*)malloc(sizeof(QueueElement));
    if (queue->list == NULL)
    {
        free(queue);
        return NULL;
    }
    return queue;
}

PriorityQueueErrorCode enqueue(PriorityQueue** const queue, 
    const int value, const int priority)
{
    if (*queue == NULL)
    {
        *queue = createQueue();
        if (*queue == NULL)
        {
            return memoryLack;
        }
    }
    if ((*queue)->size == (*queue)->capasity)
    {
        QueueElement* temp = (QueueElement*)realloc((*queue)->list, 
            2 * (*queue)->capasity * sizeof(QueueElement));
        if (temp == NULL)
        {
            deletePriorityQueue(queue);
            return memoryLack;
        }
        (*queue)->list = temp;
        (*queue)->capasity *= 2;
    }
    QueueElement newElement = { .value = value, .priority = priority };
    (*queue)->list[(*queue)->size++] = newElement;

    for (size_t i = (*queue)->size - 1; 
        i > 0 && (*queue)->list[i - 1].priority >= priority; --i)
    {
        QueueElement temp = (*queue)->list[i - 1];
        (*queue)->list[i - 1] = (*queue)->list[i];
        (*queue)->list[i] = temp;
    }

    return defaultErrorCode;
}

int dequeue(PriorityQueue* const queue)
{
    return queue->size != 0 ? queue->list[--queue->size].value : -1;
}

void deletePriorityQueue(PriorityQueue** const queue)
{
    if (queue == NULL || *queue == NULL)
    {
        return;
    }
    free((*queue)->list);
    free(*queue);
    *queue = NULL;
}
