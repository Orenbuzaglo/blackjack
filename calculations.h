#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct Culc {
    uint16_t cash,
              pot, 
              bet,
           pl_sum,
           dl_sum;
} Calc ;

void decode_card(node** hand,Calc* game);







#endif