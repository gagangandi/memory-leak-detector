#include <stdlib.h>
#include "list.h"

void *my_malloc(int size);
void my_free(void *ptr);

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    add_to_list(ptr, size);
    return ptr;
}

void my_free(void *ptr)
{
    if (ptr)
    {
        remove_from_list(ptr);
        free(ptr);
    }
}

