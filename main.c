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

    // ####################### Stage 1 - Initial stage #################################### //   
 
    // Initialaizing cards pack,player's hand and dealer's hand linked lists 
     node *deck = NULL;
     node *player_hand = NULL;
     node *dealer_hand = NULL;
     node *draw_card = NULL; 
     uint8_t suit = 1;
    // Initializing the random number generator
     srand(time(NULL)); 
     Calc game = { .cash = 1000,
                   .pot = 0,
                   .bet = 0,
                   .dl_sum = 0, 
                   .dl_ace_count = 0, 
                   .pl_sum = 0, 
                   .pl_ace_count = 0};
     
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
    
    // ####################### Stage 2 - Betting stage #################################### //

    printf("########################################################################\n"
           "#                              BLACKJACK                               #\n"
           "########################################################################\n\n\n"
           "\033[32m                      Welcome to BlackJack game!\033[0m         \n\n"
           "     You own %d in your wallet.You can bet in steps of 10's          \n\n"
           "                       place your bet : ",game.cash);
    scanf("%" SCNu16, &game.bet);
    while ((game.bet%10) || game.bet > game.cash) {
        printf("the bet shuold be in steps of 10 and not greater than your wallet.\nTry again :");
        scanf("%" SCNu16, &game.bet);
    }
    puts("");
    game.cash -= game.bet;
    game.pot += game.bet;
    printf("                      your wallet:%d       pot:%d                       \n\n",game.cash,game.pot);
    
    // ####################### Stage 3 - Initial Deal #################################### //
    
    // 2 cards for the dealer and player //
    for(int i=0 ; i < 2 ; i++) {
        card_draw(&deck, &draw_card);
        add_to_hand(&draw_card, &dealer_hand);
        card_draw(&deck, &draw_card);
        add_to_hand(&draw_card, &player_hand);
    }
    // Calculate and present player's hand //
    printf("\033[32m     Player's hand:  \033[0m"); 
    decode_print(&player_hand,&game,PLAYER);

    // Calculate and present dealer's hand //
    printf("\033[31m\n\n     Dealer's hand:  \033[0m"); 
    decode_print(&dealer_hand,&game,DEALER);

    // ####################### Stage 4 - BlackJack check #################################### //

    int pl_score = 0;
    //int dl_score = 0;
     pl_score = hand_score(&game,PLAYER);
        if (pl_score == 21) {
            printf("\n\n             you have got \033[32m BLACK JACK \033[0m\n\n ");
            game.cash += (game.pot + 1.5*game.pot);
           reset_round_data(&game,&deck,&player_hand,&dealer_hand);
        }

    // ###################### Stage 5 - Hit Or Stand ######################################## //

            else {
                char hitorstand;
                uint8_t is_playing = 1;
                while(is_playing) {
                    do {
                    printf("\n\n     Hit or Stand? (\033[32mh\033[0m for hit \033[31m s\033[0m for stand)\n      " );
                    scanf(" %c", &hitorstand);
                    }
                        while (hitorstand != 'h' && hitorstand != 's');
                
                   // The player choose Hit //
                    if (hitorstand == 'h') {
                        game.pl_sum = 0;
                        card_draw(&deck,&draw_card);
                        add_to_hand(&draw_card,&player_hand);
                        decode_print(&player_hand,&game,PLAYER);
                        pl_score = hand_score(&game, PLAYER);
                            if (pl_score > 21) {
                                printf("\nBust!\n");
                                game.pot = 0;
                                reset_round_data(&game,&deck,&player_hand,&dealer_hand);
                                is_playing = 0;
                            }
                    printf ("this is your score %d\n",pl_score);
                }   
                   
                }
                printf("end of while");
            } 
}  //This is where the main function ends //