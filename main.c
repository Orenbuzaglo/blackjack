#include <stdio.h>
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
                      .is_playing = 1,
                      .game_on = 1};
                      
        // Initialaizing cards pack,player's hand and dealer's hand linked lists //
        node *deck = NULL;
        node *player_hand = NULL;
        node *dealer_hand = NULL;
        node *drawed_card = NULL; 
        uint8_t suit = 1;
        int pl_score = 0;
        int dl_score = 0;
        char cont, hitorstand;

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

        // Game main loop //
    while(game.game_on) { 

        puts("\033[2J\033[H"); 
        
        // ####################### Stage 2 - Betting stage #################################### //

        printf("\033[33m########################################################################\n"
               "#                              BLACKJACK                               #\n"
               "########################################################################\033[0m\n\n\n"
               "\033[32m                       Welcome to BlackJack game!\033[0m         \n\n"
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
        printf("                       your wallet:%d       pot:%d                       \n\n",game.cash,game.pot);
        
        // ####################### Stage 3 - Initial Deal #################################### //
        
        // 2 cards for the dealer and player //
        for(int i=0 ; i < 2 ; i++) {
            draw_a_card(&deck, &drawed_card);
            add_to_hand(&drawed_card, &dealer_hand);
            draw_a_card(&deck, &drawed_card);
            add_to_hand(&drawed_card, &player_hand);
        }
        // Calculate and present player's hand //
        printf("\033[32m    Player's hand:    \033[0m"); 
        decode_print(&player_hand,&game,PLAYER);
        
        // Calculate and present dealer's hand //
        printf("\033[31m\n\n    Dealer's hand:    \033[0m"); 
        decode_print(&dealer_hand,&game,DEALER);

        // ####################### Stage 4 - BlackJack check #################################### //
        pl_score = hand_score(&game,PLAYER);
            if (pl_score == 21) {
                printf("\n\n                       you have got \033[32m BLACK JACK \033[0m\n\n ");
                game.cash += 2.5*game.pot;
            }

        // ###################### Stage 5 - Hit Or Stand ######################################## //

                else {
                    
                    while(game.is_playing) {
                            do {
                            printf("\n\n                       Hit or Stand? (\033[32mh\033[0m for hit \033[31m s\033[0m for stand)    " );
                            printf("Your choice: ");
                            scanf(" %c", &hitorstand);
                            }
                            while (hitorstand != 'h' && hitorstand != 's');
                        
                            //The player choose to Hit //
                            if (hitorstand == 's') game.is_playing = 0 ;
                            if (hitorstand == 'h') {
                                pl_score = pl_hit(&deck,&drawed_card,&player_hand,&game);
                                  
                            // If player has 21 , continue to Dealer's turn //
                                if (pl_score == 21) {
                                    printf("\n                       You have BlackJack \n");
                                    game.is_playing = 0 ;  
                                }
                                // If player has above 21 //
                                if (pl_score > 21) {
                                    printf("\n                       Bust!!!\n");
                                    game.pot = 0;
                                    game.is_playing = 0;
                                }
                            }                           
                        }    
                            // The player choose to Stand - Dealer's turn //
                            
                            if (pl_score <= 21) {
                                dl_score = hand_score(&game,DEALER);
                                game.dl_hide_card = 0;
                                printf("\n                       It's the Dealer's turn \n\n");
                                printf("\033[32m    Player's hand:    \033[0m");
                                decode_print(&player_hand,&game,PLAYER);
                                printf("\033[31m\n\n    Dealer's hand:    \033[0m"); 
                                decode_print(&dealer_hand,&game,DEALER);
                                if(dl_score >=17 ) decode_print(&dealer_hand,&game,DEALER);
                                
                                while (dl_score < 17) {
                                    dl_score = dl_draw(&deck,&drawed_card,&dealer_hand,&game);
                                }
                                printf("\n\n                       Your score :%d      Dealer's score :%d\n",pl_score,dl_score);
                            
                            if (dl_score > 21) {
                                printf("                       Dealer is Bust.You win\n");
                                game.cash += 2*game.pot;
                                
                            }
                            if (dl_score < pl_score) {
                                printf("                       You win\n");
                                game.cash += 2*game.pot;
                                
                            }
                            if (dl_score > pl_score && dl_score < 22) {
                                printf("                       You Loose\n");
                            }
                            }
                                
                }        
             
                printf("\n                       Let's continue? y/n : ");
                scanf(" %c", &cont); 
                    if (cont == 'Y' || cont == 'y') {
                    reset_round_data(&game,&deck,&player_hand,&dealer_hand);
                    }
                        else if (cont == 'N' || cont == 'n') {
                        return 0;
                        }

            
    } // Game on while loop //
    return 0;
        
} //This is where the main function ends //