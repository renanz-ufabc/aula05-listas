#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "element.h"


typedef struct Node Node;
typedef struct List List;


List * list_create(void);
void list_destroy(List * list);

void list_insertAtStart(List * list, Element element);
void list_insertAtEnd(List * list, Element element);
void list_print(List * list);


#endif
