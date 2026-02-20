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
    Node * head;
    size_t size;
};


List * list_create(void)
{
    List * list = malloc(sizeof(List));
    
    list->head = NULL;
    list->size = 0;

    return list;
}
void list_destroy(List * list)
{
    Node * trashNode = list->head;
    while (trashNode != NULL)
    {
        list->head = trashNode->next;
        free(trashNode);
        trashNode = list->head;
    }
}

void list_insertAtStart(List * list, Element element)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}
void list_insertAtEnd(List * list, Element element)
{
    //Node * currNode = list->head;
    //for (size_t i = 0; i < list->size - 1; i++)
    //{
        //currNode = currNode->next;
    //}
}
void list_print(List * list)
{
    Node * currNode = list->head;
    while (currNode != NULL)
    {
        element_print(currNode->element);
        currNode = currNode->next;
    }
}
