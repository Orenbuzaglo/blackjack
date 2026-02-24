#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "linkedlist.h"

typedef enum {
    HEARTS   = 0x1, // 0001
    CLUBS    = 0X2, // 0010
    DIAMONDS = 0x4, // 0100
    SPADES   = 0x8, // 1000
} CardSuit;

typedef enum {
    ACE   = 1,
    JACK  = 11,
    QUEEN = 12,
    KING  = 13,
} CardRank;

int main(void) {

    puts("\033[2J\033[H");
 
                        // Initialaizing cards pack,player's hand and dealer's hand linked lists 
     node *deck = NULL;
     node *player_hand = NULL;
     node *dealer_hand = NULL;
     node *draw_card = NULL; 
     uint16_t cash = 1000;
     uint16_t pot = 0;
     uint16_t bet; 
     uint8_t suit = 1;
     srand(time(NULL)); // Initializing the random number generator
     
                     // Initialaizing the 52 cards in the linked list          
   while (suit <= 8) {
        uint8_t rank = 1;
            while (rank <=13) {
                uint8_t fixed = (rank << 4) | suit ;
                add_to_end(&deck,fixed);
                rank++;
            }
        suit= suit<<1;
    }
    
                    // Start game - Betting stage
    printf("########################################################################\n"
           "#                              BLACKJACK                               #\n"
           "########################################################################\n\n\n"
           "                       Welcome to BlackJack game!                       \n\n"
           "     You own 1000$ in your wallet.You can bet in steps of 10's\n\n"
           "                       place your bet : ");
    scanf("%" SCNu16, &bet);
    while ((bet%10) || bet > cash) {
        printf("the bet shuold be in steps of 10 and not greater than your wallet.\nTry again :");
        scanf("%" SCNu16, &bet);
    }
    puts("");
    cash -= bet;
    pot += bet;
    printf("                      your wallet:%d       pot:%d                       \n\n",cash,pot);
    
                    // Initial Deal
    
    // 2 cards for the dealer
    for(int i=0 ; i < 2 ; i++) {
        card_draw(&deck, &draw_card);
        add_to_hand(&draw_card, &dealer_hand);
    }
    // 2 cards for the player
    for(int i=0 ; i < 2 ; i++) {
        card_draw(&deck, &draw_card);
        add_to_hand(&draw_card, &player_hand);
    }

}