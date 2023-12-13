#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../LinkedList/LinkedList.h"

void deleteOddIndexes(const List* const list)
{
    for (Index index = getFrontIndex(list); index != NULL;
        index = getNextIndex(index))
    {
        deleteNext(list, index);
    }
}

List* getArrayCopy(const int sourceArray[], const size_t sourceArraySize)
{
    List* newList = NULL;
    for (size_t i = 0; i < sourceArraySize; ++i)
    {
        pushBack(&newList, sourceArray[i]);
    }
    return newList;
}

bool test(const int testCase[], const size_t testCaseSize, 
    const int correctAnswer[], const size_t correctAnswerSize)
{
    List* tempTestCase = getArrayCopy(testCase, testCaseSize);
    deleteOddIndexes(tempTestCase);
    size_t i = 0;
    for (Index index = getFrontIndex(tempTestCase); index != NULL;
        index = getNextIndex(index), ++i)
    {
        if (i >= correctAnswerSize || correctAnswer[i] != getValueByIndex(index))
        {
            deleteList(&tempTestCase);
            return false;
        }
    }
    deleteList(&tempTestCase);
    return i == correctAnswerSize;
}

int main(void)
{
    int tempTestCase1[] = { 1, 2, 3, 4, 5 };
    const size_t testCase1Size = 5;
    int correctAnswer1[] = { 1, 3, 5 };
    const size_t correctAnswer1Size = 3;
    bool isTestPassed = test(tempTestCase1, testCase1Size, 
        correctAnswer1, correctAnswer1Size);
    printf(isTestPassed ? "Program has passed the test\n" :
        "Program has not passed the test\n");
    return 0;
}
