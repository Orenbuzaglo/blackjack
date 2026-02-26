#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "linkedlist.h"

typedef struct Culc {
    uint16_t cash,
              pot, 
              bet,
           pl_sum,
           dl_sum;
} Calc ;

// Decode and print cards
void decode_print(node** hand,Calc* game);

#endif