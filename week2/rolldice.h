#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rolldice(){
    int a = 1+rand()%6;
    int b = 1+rand()%6;
    return a+b;
}