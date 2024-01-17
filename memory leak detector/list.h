#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// Define the struct for the linked list node
struct node
{
    void *ptr;
    int size;
    bool freed;
    int bt_len;
    char bt[10][100]; // You can adjust the size as needed
    struct node *next;
};

// Declare the 'head' variable as an external variable
extern struct node *head;

void add_to_list(void *alloc_ptr, int size);
void remove_from_list(void *alloc_ptr);
void print_unfreed_ptrs();

#endif

