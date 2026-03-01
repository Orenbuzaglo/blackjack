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
           dl_ace_count;
} Calc ;

// Decode and print cards
void decode_print(node** hand,Calc* game,int is_dealer);

// Calculate hand score //
uint8_t hand_score(Calc* game, int is_dealer);

#endif