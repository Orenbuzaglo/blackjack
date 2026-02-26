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
    uint8_t rawdata = ((*hand)->data);
    uint8_t rank = rawdata >> 4;
    uint8_t suit = rawdata & 0xf ;
  
switch (rank) {
    // Ace //
    case 1: {
        game->pl_ace_count += 1;
        game->pl_sum += 11;
        //game->pl_sum += ((game->pl_sum) + 11 > 21) ? 1 : 11 ;
        printf("Ace of ");
    }
    break;
    // Jack //
    case 11: {
        printf ("Jack of ");
        game->pl_sum += 10 ;
    }
    break;
    // Queen //
    case 12: {
        printf ("Queen of ");
        game->pl_sum += 10 ;
    }
    break;
    // King //
    case 13: {
        printf ("King of ");
        game->pl_sum += 10 ;
    }
    break;

    // Cards 2-10 //
    default:
        game->pl_sum += rank;
        printf("%" PRIu8 " of ", rank);
    break;
}
    // Let's add the suit //
switch (suit) {
case 1: printf("Hearts");   break;
case 2: printf("Clubs");    break;
case 4: printf("Diamonds"); break;
case 8: printf("Spades");   break;
}
}
