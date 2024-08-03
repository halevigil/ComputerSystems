#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"
#include <stdint.h>
/*
* Gil Halevi
* implemented all the below methods
*/

int is_special ( float f ) {
    return isnan(f) || isinf(f);
}


float get_M  ( float f ) {
    if (isinf(f)|| isinf(-f)) return 0;
    if (isnan(f)) return 1;

    printf("int:%x\n",(uint32_t )f);
    f=f*get_s(f); // get absolute value
    if (f == 0.0f) return 0;
    int i = 0;
    // if bigger than 1, divide by 2 until leading digit is 1 or until exponent is full
    while (f>= 2 && i < 128){
        f/=2;
        i++;
    }
    // if smaller than 1, multiply by 2 until leading digit is 1 or until exponent is full
    while (f < 1 && i<126){
        f*= 2;
        i++;
    }
    return f;
}


int get_s ( float f ) {
    if (signbit(f)==0){
        return 1;
    } else{
        return -1;
    }
}



int get_E ( float f ) {
    if (isinf(f)) return 255;
    if (isnan(f)) return 255;
    int out=0;
    f=f*get_s(f); // get absolute value
    if (f == 0.0f) return 0;
    // if float smaller than 1, increment out by 1 and multiply exponent by 2
    // until leading digit of float is 1 or until exponent is full
    while (f >= 2 && out < 128){
        out++;
        f/=2;
    }
    // if float smaller than 1, decrement out by 1 and multiply exponent by 2
    // until leading digit of float is 1 or until exponent is full
    while (f < 1 && out > -126){
        out--;
        f*= 2;
    }
    return out;
}













      



    
    
