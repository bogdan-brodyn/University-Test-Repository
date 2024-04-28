#include <stdio.h>
#include <stdbool.h>

#include "../PriorityQueue/PriorityQueue.h"

bool test(void)
{
    PriorityQueue* queue = NULL;
    bool testPassed =
        enqueue(&queue, 1, 1) == defaultErrorCode
        && enqueue(&queue, 3, 3) == defaultErrorCode
        && enqueue(&queue, 2, 2) == defaultErrorCode
        && enqueue(&queue, 4, 3) == defaultErrorCode
        && dequeue(queue) == 3
        && dequeue(queue) == 4
        && dequeue(queue) == 2
        && dequeue(queue) == 1
        && dequeue(queue) == -1;
    deletePriorityQueue(&queue);
    return testPassed && queue == NULL;
}

int main(void)
{
    printf(test() ? "Program passed the test\n" : "Program failed the test\n");
}
