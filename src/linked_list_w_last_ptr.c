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
    if (index == list->size) { list_insertAtEnd(list, element); return; }

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
    if (list->size == 1) { list->last = NULL; }
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
    list->last = secondToLast;

    list->size--;
}
void list_remove(List * list, size_t index)
{
    if (index == 0) { list_removeFirst(list); return; }
    if (index >= list->size) { list_error("Invalid index to remove"); return; }
    if (index == list->size - 1) { list_removeLast(list); return; }

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

    if (index == list->size - 1) { list->last = prev; }
    Node * moving = prev->next;
    prev->next = prev->next->next;
    moving->next = list->first;
    list->first = moving;
}
void list_moveToEnd(List * list, size_t index)
{
    if (index == list->size - 1) { return; }
    if (index < 0 || index >= list->size) { list_error("Invalid index to move"); return; }

    if (index == 0)
    {
        Node * moving = list->first;
        list->first = list->first->next;
        moving->next = NULL;
        list->last->next = moving;
        list->last = moving;
        return;
    }

    Node * prev = list->first;
    for (size_t i = 0; i < index - 1; i++) { prev = prev->next; }

    Node * moving = prev->next;
    prev->next = prev->next->next;
    moving->next = NULL;
    list->last->next = moving;
    list->last = moving;
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
void list_printFirst(List * list)
{
    if (list->first == NULL) { return; }
    element_print(list->first->element);
}
void list_printLast(List * list)
{
    if (list->last == NULL) { return; }
    element_print(list->last->element);
}
void list_printFirstAndLast(List * list)
{
    printf("(");
    list_printFirst(list);
    printf(", ");
    list_printLast(list);
    printf(")\n");
}
