// implement your program here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// concatenates the 3 color values to one 6-long hex number
// @param vals: the 3 color values
// @return 6-long hex number
int colorToHex(int vals[3]){
    int i;
    int color=0;

    // for all 3 color values, make sure value is valid and append it to color
    for (i=0;i<3;i++){
        color=color<<8; 
        if (!((vals[i]>=0)&(vals[i]<=255))){
            return -1;
        }
        color=color|vals[i];
    }
    return color;
}

int main(){
    int nLines;
    scanf("%d",&nLines);
    int input[3];
    int rrggbb;
    // for nLines, get the 3 color values and print hex representation or INVALID
    while (nLines>0){
        scanf("%d%*c %d%*c %d%*c",input,input+1,input+2);
        rrggbb=colorToHex(input);
        if (rrggbb==-1){
            printf("INVALID\n");
        }
        else{
            printf("%06x\n",rrggbb);
        }
        nLines--;
    }
    return 0;
}




