#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    Element element;
    struct Node * prev;
    struct Node * next;
};
struct List
{
    Node * sentinel;
    size_t size;
};


Node * list_createNode(Element element)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->element = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}
void list_error(const char * message)
{
    fprintf(stderr, "<! ERROR: %s !>\n", message);
}


List * list_create(void)
{
    List * list = malloc(sizeof(List));

    list->sentinel = malloc(sizeof(Node));
    list->sentinel->prev = list->sentinel;
    list->sentinel->next = list->sentinel;

    return list;
}
void list_destroy(List * list)
{
    Node * curr = list->sentinel->next;
    while (curr != list->sentinel)
    {
        Node * trash = curr;
        curr = curr->next;
        free(trash);
    }
    free(list->sentinel);
    free(list);
}

size_t list_getSize(List * list)
{
    return list->size;
}
bool list_isEmpty(List * list)
{
    return list->sentinel->next == list->sentinel;
}

void list_insertAtStart(List * list, Element element)
{
    Node * newNode = list_createNode(element);

    newNode->prev = list->sentinel;
    newNode->next = list->sentinel->next;
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;

    list->size++;
}
void list_insertAtEnd(List * list, Element element)
{
    Node * newNode = list_createNode(element);

    newNode->next = list->sentinel;
    newNode->prev = list->sentinel->prev;
    newNode->next->prev = newNode;    
    newNode->prev->next = newNode;

    list->size++;
}

void list_removeFirst(List * list)
{
    // ...
}
void list_removeLast(List * list)
{
    // ...
}

void list_print(List * list)
{
    list_printForward(list);
}
void list_printForward(List * list)
{
    Node * curr = list->sentinel->next;
    printf("[ ");
    while (curr != list->sentinel)
    {
        element_print(curr->element);
        if (curr->next != list->sentinel) { printf(" <-> "); }

        curr = curr->next;
    }
    printf(" ], size = %zu", list_getSize(list));
}
void list_printBackward(List * list)
{
    Node * curr = list->sentinel->prev;
    printf("[ ");
    while (curr != list->sentinel)
    {
        element_print(curr->element);
        if (curr->prev != list->sentinel) { printf(" <-> "); }

        curr = curr->prev;
    }
    printf(" ], size = %zu", list_getSize(list));
}
