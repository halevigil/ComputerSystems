#include "rolldice.h"
#include <stdbool.h>
#include <stdio.h>

bool simulate(){
    int original = rolldice();
    if (original==7){
        return true;
    }
    int newroll=-1;
    while (newroll!=7){
        newroll=rolldice();
        if (newroll==original){
            return true;
        }
    }
    return false;
}

int main(){
    int wins = 0;
    int runs;
    bool res;
    srand(time(0));
    for (runs=0;runs<1000;runs++){
        res=simulate();
        if (res){
            wins++;
        }
        
    }
    printf("%d wins \n",wins);
    printf("%d losses",runs-wins);
}