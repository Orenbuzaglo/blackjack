#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#define DEALER 1
#define PLAYER 0

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "linkedlist.h"

typedef struct Calc {
    uint16_t cash,
              pot, 
              bet,
           pl_sum,
           pl_ace_count,
           dl_sum,
           dl_ace_count,
           dl_hide_card,
           game_on;
} Calc ;

// Decode and print cards
void decode_print(node** hand,Calc* game,int is_dealer);

// Calculate hand score //
uint8_t hand_score(Calc* game, int is_dealer);

// reset round data //
void reset_round_data(Calc* game,node** deck,node** player_hand,node** dealer_hand);

// Dealer draw //
int dl_draw(node** deck,node** drawed_card,node** dealer_hand,node** player_hand,Calc* game);

// Player choose 'hit' //
int pl_hit(node** deck,node** drawed_card,node** player_hand,Calc* game);

#endif