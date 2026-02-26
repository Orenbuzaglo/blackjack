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
    uint8_t rawdata = ((*hand)->data);
    uint8_t rank = rawdata >> 4;
    uint8_t suit = rawdata & 0xf ;




}