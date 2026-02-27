#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stdbool.h>
#include <stddef.h>
#include "element.h"


typedef struct Node Node;
typedef struct List List;


List * list_create(void);
void list_destroy(List * list);

//void list_set(List * list, size_t index, Element element);
//Element list_get(List * list, size_t index);
size_t list_getSize(List * list);
bool list_isEmpty(List * list);

void list_insertAtStart(List * list, Element element);
void list_insertAtEnd(List * list, Element element);
//void list_insertAt(List * list, size_t index, Element element);

void list_removeFirst(List * list);
void list_removeLast(List * list);
//void list_remove(List * list, size_t index);

//void list_moveToStart(List * list, size_t index);
//void list_moveToEnd(List * list, size_t index);

void list_print(List * list);
void list_printForward(List * list);
void list_printBackward(List * list);


#endif




/*
 *      ***  NOTE  ***
 *
 *  Doubly linked lists possibilities:
 *      1) basic;
 *      2) circular;
 *      3) circular w/ sentinel node;
 *
 *  This module uses option 3.
 *
 */
