#pragma once

typedef enum
{
    defaultLinkedListErrorCode,
    memoryLackLinkedListErrorCode,
    nullPointerLinkedListErrorCode
} LinkedListErrorCode;

typedef struct List List;

typedef struct ListElement ListElement;

typedef ListElement* Index;

Index getFrontIndex(const List* const list);

Index getNextIndex(const Index index);

Index getValueByIndex(const Index index);

LinkedListErrorCode pushBack(List** const list, const int value);

void deleteNext(List* list, const Index index);

void deleteList(List** const list);
