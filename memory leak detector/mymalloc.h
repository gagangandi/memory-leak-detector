#ifndef MYMALLOC_H
#define MYMALLOC_H

#include<stdlib.h>
#include "list.h"


void *my_malloc(int size);
void my_free(void *ptr);
#endif
