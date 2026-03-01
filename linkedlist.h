#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct node {
    uint8_t data;
    struct node* next;
} node ;

void check_allocation(void* ptr);
void add_to_end(node** head,uint8_t val);
void free_list(node* head);
void print_list(node* head);
int list_length(node* head);
void card_draw(node** deck,node** draw_card);
void add_to_hand(node** card_draw,node** hand);
void return_to_deck(node** deck,node** hand);

#endif
