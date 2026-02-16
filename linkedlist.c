#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

/* Function to validate dynamic allocation success */

void check_allocation(void* ptr) {
    if ( ptr == NULL) {
        printf(" Dynamic allocation failed.\n");
        exit(1);
    }
}

/* Fanction to create head or add a node to the tail*/

node* add_to_end(node* head,int val) {
    node* newNode=(node*)malloc(sizeof(node));
    check_allocation(newNode);
    newNode->data = val;
    newNode->next = NULL;
    /* If head is the only one node it will get the newNode*/
    if(head == NULL) 
    return newNode;

    /* Searching the last node that holds NULL */
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // It will add a next in any iteration untill NULL will be presented(temp->next->next ...)
        }    
        temp->next = newNode; // Put the new node to the last so the newNode is the last one  
        
        return head;
    }

 /* Function to free linked list */

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
 
  /* Function to print linked list */
void print_list(node* head) {
    node* phead = head ;

    while (phead) {
        printf("%d ", phead->data);
        phead = phead->next;
        }
}