#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "linkedlist.h"
#include "calculations.h"



void decode_print(node** hand,Calc* game,int is_dealer) {

    int cardcount = 0;
    node* current = *hand;
    while (current != 0) {
    uint8_t rawdata = current->data;
    uint8_t rank = rawdata >> 4;
    uint8_t suit = rawdata & 0xf ;
    
  
switch (rank) {
    // Ace //
    case 1: {
        game->pl_ace_count += 1;
        game->pl_sum += 11;
        cardcount += 1;
        if(is_dealer && cardcount > 1 ) printf("????????");
        else
        printf("Ace of ");
    }
    break;
    
    case 11: {
        
        game->pl_sum += 10 ;
        cardcount += 1;
        if(is_dealer && cardcount > 1 ) printf("????????");
        else
        printf ("Jack of ");
    }
    break;
    
    case 12: {
        game->pl_sum += 10 ;
        cardcount += 1;
        if(is_dealer && cardcount > 1 ) printf("????????");
        else
        printf ("Queen of ");
        
    }
    break;
    
    case 13: {
        
        game->pl_sum += 10 ;
        cardcount += 1;
        if(is_dealer && cardcount > 1 ) printf("????????");
        else
        printf ("King of ");
    }
    break;

    // Cards 2-10 //
    default:
        game->pl_sum += rank;
        cardcount += 1;
        if(is_dealer && cardcount > 1 ) printf("????????");
        else
        printf("%" PRIu8 " of ", rank);
    break;
}
    // Let's add the suit //
    
     while(is_dealer && cardcount <= 1)  
        switch (suit) {
        case 1: printf("Hearts  ");   break;
        case 2: printf("Clubs   ");    break;
        case 4: printf("Diamonds    "); break;
        case 8: printf("Spades  ");   break;
        }
        
current = (node*)current->next ;
}
printf("\n\n\n");
}


