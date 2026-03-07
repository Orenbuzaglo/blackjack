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

// validate dynamic allocation success //
void check_allocation(void* ptr);

// create head or add a node to the tail //
void add_to_end(node** head,uint8_t val);

// free linked list //
void free_list(node* head);

// print linked list //
void print_list(node* head);

// Linked list length //
int list_length(node* head);

// Card draw from deck to player //
void draw_a_card(node** deck,node** drawed_card);

// Add the drawed_card to hand //
void add_to_hand(node** draw_a_card,node** hand);

// Return cards to the deck //
void return_to_deck(node** deck,node** hand);

#endif
