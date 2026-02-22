#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

typedef struct node {
    uint8_t data;
    struct node* next;
} node ;

void check_allocation(void* ptr);
void add_to_end(node **head,int val);
void free_list(node* head);
void print_list(node* head);

#endif
