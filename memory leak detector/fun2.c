#include "mymalloc.h"
#define malloc my_malloc
#define free my_free

void fun44();

void fun44() {
	malloc(sizeof(int));
}
