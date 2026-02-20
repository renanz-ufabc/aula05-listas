#include <stdio.h>
#include "linked_list.h"


int main(void)
{
    List * list = list_create();
    for (size_t i = 0; i < 10; i++)
    {
        list_insertAtStart(list, i);
    }
    list_print(list);

    return 0;
}
