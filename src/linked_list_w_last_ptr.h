#ifndef LINKED_LIST_W_LAST_PTR_H
#define LINKED_LIST_W_LAST_PTR_H
#include <stdbool.h>
#include <stddef.h>
#include "element.h"


typedef struct Node Node;
typedef struct List List;


List * list_create(void);
void list_destroy(List * list);

void list_set(List * list, size_t index, Element element);
Element list_get(List * list, size_t index);
size_t list_getSize(List * list);
bool list_isEmpty(List * list);

void list_insertAtStart(List * list, Element element);
void list_insertAtEnd(List * list, Element element);
void list_insertAt(List * list, size_t index, Element element);

void list_removeFirst(List * list);
void list_removeLast(List * list);
void list_remove(List * list, size_t index);

void list_moveToStart(List * list, size_t index);
void list_moveToEnd(List * list, size_t index);

void list_print(List * list);


#endif
