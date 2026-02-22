#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"



int main(void) {
 
   // Initialaizing cards pack,player's hand and dealer's hand linked lists 
    node *deck = NULL;
    node *player_hand = NULL;
    node *dealer_hand = NULL; 
    int cash = 1000;
    int pot = 0;

   // Initialaizing the 52 cards in the linked list 
   uint8_t suit = 1;
   while (suit <= 8) {
        uint8_t rank = 0;
        while (rank <=12) {
        uint8_t fixed = (rank << 4) | suit ;
        add_to_end(&deck,fixed);
        rank++;
        }
        suit= suit<<1;
    }
    printf("total lenght of the linked list is %d \n", list_length(deck));


}