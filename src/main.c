#include <stdio.h>
#include "linked_list.h"

#define SHOW_LIST(L) { list_print(L); printf("\n"); }


int main(void)
{
    List * list = list_create();

    SHOW_LIST(list);

    for (size_t i = 0; i <= 10; i++)
    {
        list_insertAtStart(list, -i);
    }
    SHOW_LIST(list);
    for (size_t i = 1; i <= 10; i++)
    {
        list_insertAtEnd(list, i);
    }
    SHOW_LIST(list);

    list_removeFirst(list);
    list_removeLast(list);
    SHOW_LIST(list);

    list_insertAt(list, 8, 88);
    SHOW_LIST(list);
    list_remove(list, 8);
    SHOW_LIST(list);

    list_set(list, 2, 22);
    SHOW_LIST(list);
    element_print(list_get(list, 2));
    printf("\n");

    list_destroy(list);

    return 0;
}
