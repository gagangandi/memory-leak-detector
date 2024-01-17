#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <execinfo.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

struct node *head = NULL;

void add_to_list(void *alloc_ptr, int size)
{
    void *buffer[100];
    char **strings;
    struct node *ptr, *temp;
    int nptrs;
    int item;
    nptrs = backtrace(buffer, 100);

    ptr = (struct node *)malloc(sizeof(struct node));
    strings = backtrace_symbols(buffer, nptrs);
    if (strings == NULL)
    {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->ptr = alloc_ptr;
        ptr->size = size;
        ptr->freed = false;
        ptr->bt_len = nptrs;
        int i = 0;
        for (; i < nptrs; i++)
        {
            strcpy(ptr->bt[i], strings[i]);
        }
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            temp->ptr = alloc_ptr;
            temp->size = size;
            ptr->bt_len = nptrs;
            for (; i < nptrs; i++)
            {
                strcpy(temp->bt[i], strings[i]);
            }
            ptr->freed = false;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}

void remove_from_list(void *alloc_ptr)
{
    struct node *ptr, *temp;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->ptr == alloc_ptr)
        {
            temp->ptr = NULL; // Fixed the comparison operator
            temp->freed = true;
            temp->size = 0;
            printf("\nRemoved from the list\n");
        }
        temp = temp->next;
    }
}

void print_unfreed_ptrs()
{
    struct node *ptr, *temp;
    temp = head;
    printf("printing unfreed\n");
    while (temp->next != NULL)
    {
        if (temp->freed != true)
        {
            printf("%p is not freed with size %d\n", temp->ptr, temp->size); // Fixed the format specifier
            int j = 0;
            for (; j < temp->bt_len; j++)
            {
                printf("%s\n", temp->bt[j]);
            }
        }
        temp = temp->next;
    }
    if (temp->freed != true)
    {
        printf("%p is not freed with size %d\n", temp->ptr, temp->size); // Fixed the format specifier
        int j = 0;
        for (; j < temp->bt_len; j++)
        {
            printf("%s\n", temp->bt[j]);
        }
    }
}

