#include <stdio.h>
int main(){
    int x = 1;
    x=~x;
    if (x){
        printf("x=%d \n",x);
        printf("worked!");
    }
}