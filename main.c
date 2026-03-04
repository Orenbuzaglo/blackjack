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

    // ####################### Stage 1 - Initial stage #################################### //   
 
        puts("\033[2J\033[H");
        Calc game = { .cash = 1000,
                      .pot = 0,
                      .bet = 0,
                      .dl_sum = 0, 
                      .dl_ace_count = 0, 
                      .pl_sum = 0, 
                      .pl_ace_count = 0,
                      .dl_hide_card = 1,
                      .game_on = 1};

    while(game.game_on) { 
        puts("\033[2J\033[H");                
        // Initialaizing cards pack,player's hand and dealer's hand linked lists //
        node *deck = NULL;
        node *player_hand = NULL;
        node *dealer_hand = NULL;
        node *drawed_card = NULL; 
        uint8_t suit = 1;
        int pl_score = 0;
        int dl_score = 0;
        char cont;

        // Initializing the random number generator //
        srand(time(NULL)); 

        // Initialaizing the 52 cards in the linked list //         
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
            "     You own %d$ in your wallet.You can bet in steps of 10's          \n\n"
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
            draw_a_card(&deck, &drawed_card);
            add_to_hand(&drawed_card, &dealer_hand);
            draw_a_card(&deck, &drawed_card);
            add_to_hand(&drawed_card, &player_hand);
        }
        // Calculate and present player's hand //
        printf("\033[32m     Player's hand:  \033[0m"); 
        decode_print(&player_hand,&game,PLAYER);
        
        // Calculate and present dealer's hand //
        printf("\033[31m\n\n     Dealer's hand:  \033[0m"); 
        decode_print(&dealer_hand,&game,DEALER);

        // ####################### Stage 4 - BlackJack check #################################### //
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
                        printf("\n\n     Hit or Stand? (\033[32mh\033[0m for hit \033[31m s\033[0m for stand)\n     " );
                        printf("Your choice: ");
                        scanf(" %c", &hitorstand);
                        }
                        while (hitorstand != 'h' && hitorstand != 's');
                    
                        //The player choose to Hit //
                        if (hitorstand == 'h') {
                            // Adding a card and calculate //
                            pl_score = pl_hit(&deck,&drawed_card,&player_hand,&game);
                            printf("player's score %d",pl_score);
                            // If player has 21 , continue to Dealer's turn //
                            if (pl_score == 21) {
                                printf("\nYou have BlackJack,now its Dealer's turn\n");
                                is_playing = 0 ;
                                hitorstand = 's';    
                            }
                            // If player has above 21 //
                            if (pl_score > 21) {
                                printf("\nBust!!!\n");
                                game.pot = 0;
                                reset_round_data(&game,&deck,&player_hand,&dealer_hand);
                                is_playing = 0;
                            }
                        }        
                        // The player choose to Stand - Dealer's turn //
                        if (hitorstand == 's') {
                            game.dl_hide_card = 0;
                            do {
                            dl_score = dl_draw(&deck,&drawed_card,&dealer_hand,&player_hand,&game);
                            if (dl_score > 21) {
                                printf("\ndealer is busted\n");
                                is_playing = 0;
                            }

                            }
                            while (dl_score<17);
                            
                        
                        }   
                }
                      game.pot = 0,
                      game.bet = 0,
                      game.dl_sum = 0, 
                      game.dl_ace_count = 0, 
                      game.pl_sum = 0, 
                      game.pl_ace_count = 0,
                      game.dl_hide_card = 1,
                      game.game_on = 1; 
                printf("\nLet's continue? y/n :\n");
                scanf(" %c", &cont);
                
            }  
    } // Game on while loop //
        
} //This is where the main function ends //