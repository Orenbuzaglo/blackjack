#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "linkedlist.h"
#include "calculations.h"

int main(void) {

    puts("\033[2J\033[H");
 
    // Initialaizing cards pack,player's hand and dealer's hand linked lists 
     node *deck = NULL;
     node *player_hand = NULL;
     node *dealer_hand = NULL;
     node *draw_card = NULL; 
     uint8_t suit = 1;
    // Initializing the random number generator
     srand(time(NULL)); 
     Calc game = { .cash = 1000, .pot = 0, .bet = 0, .dl_sum = 0, .dl_ace_count = 0, .pl_sum = 0, .pl_ace_count = 0};
     
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
           "\033[32m                      Welcome to BlackJack game!\033[0m         \n\n"
           "     You own 1000$ in your wallet.You can bet in steps of 10's          \n\n"
           "                       place your bet : ");
    scanf("%" SCNu16, &game.bet);
    while ((game.bet%10) || game.bet > game.cash) {
        printf("the bet shuold be in steps of 10 and not greater than your wallet.\nTry again :");
        scanf("%" SCNu16, &game.bet);
    }
    puts("");
    game.cash -= game.bet;
    game.pot += game.bet;
    printf("                      your wallet:%d       pot:%d                       \n\n",game.cash,game.pot);
    
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
    // Calculate and present player's hand //
    printf("player's hand: "); 
    decode_print(&player_hand,&game,PLAYER);

    // Calculate and present dealer's hand //
    printf("\nDealer's hand: "); 
    decode_print(&dealer_hand,&game,DEALER);
}