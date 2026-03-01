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
   
    node* current = *hand;
    int cardcount = 0;
        while (current != 0) {
            // Counting and presenting Player's hand //
            if (is_dealer == 0) {
            uint8_t rawdata = current->data;
            uint8_t rank = rawdata >> 4;
            uint8_t suit = rawdata & 0xf;
        
                switch (rank) {
                case 1: {
                    game->pl_ace_count += 1;
                    game->pl_sum += 11;
                    printf("Ace of ");
                }
                break;
            
                case 11: {
                    game->pl_sum += 10 ;
                    printf ("Jack of ");
                }
                break;
            
                case 12: {
                    game->pl_sum += 10 ;
                    printf ("Queen of ");
                    
                }
                break;
                
                case 13: {   
                    game->pl_sum += 10 ;
                    printf ("King of ");
                }
                break;

                // Cards 2-10 //
                default: {
                    game->pl_sum += rank;
                    printf("%" PRIu8 " of ", rank);
                }
                break;
            }
            // Let's add the suit //    
            switch (suit) {
                case 1: printf("Hearts  ");     break;
                case 2: printf("Clubs   ");     break;
                case 4: printf("Diamonds    "); break;
                case 8: printf("Spades  ");     break;
            }        
            current = (node*)current->next ;
            }
            // Counting and presenting Dealer's hand //
            else {
                uint8_t rawdata = current->data;
                int8_t rank = rawdata >> 4;
                uint8_t suit = rawdata & 0xf;
            switch (rank) {
                case 1: {
                    game->dl_ace_count += 1;
                    game->dl_sum += 11;
                    if(cardcount) printf("????????");
                    else
                    printf("Ace of ");
                    cardcount ++;
                }
                break;
        
                case 11: {
                    game->dl_sum += 10 ;
                    if(cardcount) printf("????????");
                    else
                    printf ("Jack of ");
                    cardcount ++;
                }
                break;
        
                case 12: {
                    game->dl_sum += 10 ;
                    if(cardcount) printf("????????");
                    else
                    printf ("Queen of ");
                    cardcount ++;
                    
                }
                break;
                
                case 13: {
                    
                    game->dl_sum += 10 ;
                    if(cardcount) printf("????????");
                    else
                    printf ("King of ");
                    cardcount ++;
                }
                break;

                // Cards 2-10 //
                default:
                    game->dl_sum += rank;
                    if(cardcount) printf("????????");
                    else
                    printf("%" PRIu8 " of ", rank);
                    cardcount ++;
                break;
            }
                // Let's add the suit //
            if(cardcount < 2) 
                    switch (suit) {
                        case 1: printf("Hearts  ");     break;
                        case 2: printf("Clubs   ");     break;
                        case 4: printf("Diamonds    "); break;
                        case 8: printf("Spades  ");     break;
                    }
                else
                    printf(" ");
            
            current = (node*)current->next ;
            }    
        }
}
    // Calculate hand score //
    uint8_t hand_score(Calc* game, int is_dealer) {
        uint8_t score = 0 ;
        uint8_t aces = 0 ;
        if(is_dealer) {
            score = game->dl_sum;
            aces = game->dl_ace_count ;
        }
            else {
                score = game->pl_sum;
                aces = game->pl_ace_count ;
            }

        while (score > 21 && aces > 0 ) {
            score -= 10;
            aces --;
        }
        return score;        
    }
    // reset round data //
    void reset_round_data(Calc* game,node** deck,node** player_hand,node** dealer_hand) {
        game->pot = 0;
            game->bet = 0;
            game->dl_sum = 0; 
            game->dl_ace_count = 0;
            game->pl_sum = 0;
            game->pl_ace_count = 0;
            return_to_deck(deck,player_hand);
            return_to_deck(deck,dealer_hand);
    }

