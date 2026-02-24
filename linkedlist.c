#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include "linkedlist.h"

/* validate dynamic allocation success */

void check_allocation(void* ptr) {
    if ( ptr == NULL) {
        printf(" Dynamic allocation failed.\n");
        exit(1);
    }
}

/* create head or add a node to the tail*/

void add_to_end(node **head,int val) {
    node *newNode=(node*)malloc(sizeof(node));
    check_allocation(newNode);
    newNode->data = val;
    newNode->next = NULL;
    /* If head is NULL it will get the newNode*/
    if(*head == NULL) {
    *head = newNode;
    return;
    }

    /* Searching the last node that holds NULL */
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // It will add a next in any iteration untill NULL will be presented(temp->next->next ...)
        }    
        temp->next = newNode; // Put the new node to the last so the newNode is the last one  
        return;
    }

 /* free linked list */

void free_list(node* head) {
    if(!head) {
        printf("No list to free\n");
        return;
    }
    node* current = head;
    node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;    
    }   
 }  
 
  /* print linked list */
void print_list(node* head) {
    node* phead = head ;

    while (phead) {
        printf("%d ", phead->data);
        phead = phead->next;
        }
}

  /* Linked list length */
  int list_length(node *head){
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count+=1;
    }
    return count;
  }

  /* Card draw from deck to player */
  
  void card_draw(node** deck,node** draw_card) {
    // Validate that the deck is not empty
    if((*deck) == NULL) {
        printf("The deck is empty\n");
        return;
    }
    node* curr = *deck;
    node* prev = NULL;
    int target;
    // get random number in deck's cards range
    target = rand() % list_length(*deck);

    // In case rand returned 0
        if (target == 0) {
            *draw_card = *deck ;
            *deck = (*deck)->next;
            (*draw_card)->next = NULL;
            return ;
        }
    while (target > 0) {
        prev = curr;
        curr = curr->next;
        target--;
    }
    prev->next = curr->next;
    *draw_card = curr;
    (*draw_card)->next = NULL;
    return;
  }

  // Add the draw_card to hand
  void add_to_hand(node** card_draw,node** hand) {
    node* temp = *hand;
    if(temp == NULL) {
        *hand = *card_draw;
    }
    else {
        while (temp->next != NULL ) {
            temp = temp->next ;
        }
        temp->next = *card_draw;
    }
  }