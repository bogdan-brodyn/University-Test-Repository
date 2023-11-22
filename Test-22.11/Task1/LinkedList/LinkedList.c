#include <stdlib.h>

#include "LinkedList.h"

struct ListElement
{
    int index;
    int value;
    struct ListElement* next;
};

struct List
{
    ListElement* front;
    ListElement* back;
};

Index getFrontIndex(const List* const list)
{
    return list->front;
}

Index getNextIndex(const Index index)
{
    return index != NULL ? index->next : NULL;
}

Index getValueByIndex(const Index index)
{
    return index->value;
}

LinkedListErrorCode pushBack(List** const list, const int value)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return memoryLackLinkedListErrorCode;
    }
    newElement->value = value;

    if (*list == NULL)
    {
        *list = (List*)calloc(1, sizeof(List));
        if (*list == NULL)
        {
            free(newElement);
            return memoryLackLinkedListErrorCode;
        }
        newElement->index = 0;
        (*list)->front = newElement;
        (*list)->back = newElement;
        return defaultLinkedListErrorCode;
    }

    newElement->index = (*list)->back->index + 1;
    (*list)->back->next = newElement;
    (*list)->back = newElement;
    return defaultLinkedListErrorCode;
}

void deleteNext(List* list, const Index index)
{
    ListElement* currentListElement = (ListElement*)index;
    ListElement* listElementToDelete = currentListElement->next;
    if (listElementToDelete == NULL)
    {
        return;
    }
    if (listElementToDelete == list->back)
    {
        list->back = currentListElement;
    }
    currentListElement->next = currentListElement->next->next;
    free(listElementToDelete);
}

void deleteList(List** const list)
{
    while ((*list)->front != (*list)->back)
    {
        deleteNext(*list, (*list)->front);
    }
    free((*list)->front);
    free(*list);
    *list = NULL;
}
