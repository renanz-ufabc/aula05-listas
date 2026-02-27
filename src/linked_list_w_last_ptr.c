#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    Element element;
    struct Node * next;
};
struct List
{
    Node * first;
    Node * last;
    size_t size;
};


void list_error(const char * message)
{
    fprintf(stderr, "<! ERROR: %s !>\n", message);
}


List * list_create(void)
{
    List * list = malloc(sizeof(List));
    
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}
void list_destroy(List * list)
{
    Node * trash = list->first;
    while (trash != NULL)
    {
        list->first = trash->next;
        free(trash);
        trash = list->first;
    }
    free(list);
}

void list_set(List * list, size_t index, Element element)
{
    if (index < 0 || index >= list->size) { list_error("Invalid index to set"); return; }

    Node * target = list->first;
    for (size_t i = 0; i < index; i++) { target = target->next; }

    target->element = element;
}
Element list_get(List * list, size_t index)
{
    if (index < 0 || index >= list->size) { list_error("Invalid index to get [invalid return: 0]"); return 0; }

    Node * target = list->first;
    for (size_t i = 0; i < index; i++) { target = target->next; }

    return target->element;
}
size_t list_getSize(List * list)
{
    return list->size;
}
bool list_isEmpty(List * list)
{
    return list->first == NULL;
}

void list_insertAtStart(List * list, Element element)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->element = element;

    newNode->next = list->first;
    list->first = newNode;
    if (list->last == NULL) { list->last = newNode; }

    list->size++;
}
void list_insertAtEnd(List * list, Element element)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->element = element;
    
    if (list_isEmpty(list))
    {
        list->first = newNode;
    }
    else
    {
        newNode->next = list->last->next;
        list->last->next = newNode;
    }
    list->last = newNode;
    
    list->size++;
}
void list_insertAt(List * list, size_t index, Element element)
{
    if (index == 0) { list_insertAtStart(list, element); return; }
    if (index > list->size) { list_error("Invalid index to insert"); return; }

    Node * prev = list->first;
    for (size_t i = 0; i < index - 1; i++) { prev = prev->next; }

    Node * newNode = malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = prev->next;
    prev->next = newNode;

    list->size++;
}

void list_removeFirst(List * list)
{
    if (list_isEmpty(list)) { list_error("List already empty"); return; }

    Node * trash = list->first;
    list->first = list->first->next;
    free(trash);

    list->size--;
}
void list_removeLast(List * list)
{
    if (list_isEmpty(list)) { list_error("List already empty"); return; }
    if (list->size < 2) { list_removeFirst(list); return; }

    Node * secondToLast = list->first;
    while (secondToLast->next->next != NULL) { secondToLast = secondToLast->next; }

    free(secondToLast->next);
    secondToLast->next = NULL;

    list->size--;
}
void list_remove(List * list, size_t index)
{
    if (index == 0) { list_removeFirst(list); return; }
    if (index >= list->size) { list_error("Invalid index to remove"); return; }

    Node * prev = list->first;
    for (size_t i = 0; i < index - 1; i++) { prev = prev->next; }

    Node * trash = prev->next;
    prev->next = trash->next;
    free(trash);

    list->size--;
}

void list_moveToStart(List * list, size_t index)
{
    if (index == 0) { return; }
    if (index < 0 || index >= list->size) { list_error("Invalid index to move"); return; }

    Node * prev = list->first;
    for (size_t i = 0; i < index - 1; i++) { prev = prev->next; }

    // ...
}
void list_moveToEnd(List * list, size_t index)
{
    // ...
}

void list_print(List * list)
{
    Node * curr = list->first;
    printf("[ ");
    while (curr != NULL)
    {
        element_print(curr->element);
        if (curr->next != NULL) { printf(" -> "); }

        curr = curr->next;
    }
    printf(" ], size = %zu", list_getSize(list));
}
