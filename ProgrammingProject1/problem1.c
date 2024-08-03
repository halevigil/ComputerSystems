// implement your program here
#include <stdint.h>
#include <stdio.h>
#include <string.h>



int inRange(int i, int min, int max);

/*
*   checks if the given integer is in the given range
*   @param i: the integer to be checked
*   @param min: the minimum allowable value, inclusive
*   @param max: the maximum allowable value, inclusive
*   @return true if min<=i<=max, false otherwise
*/
int inRange(int i, int min, int max){
    return (i>=min)&(i<=max);
}

/* compress the given date, given as a 14 digit string, into a 32-bit integer
*   @param date: the given date in "MM/DD hh:mm:ss" format
*   @return 32-bit representation of the date as specified by the problem, or -1 if the date is invalid.
*/
int compressDate(char date[5][2]){
    const int tensDigitMax[5] = {1,3,2,5,5}; 
    const int tensDigitBits[5] = {1,2,2,3,3};
    const int maxDay[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    int out = 0;
    int digit;
    int group;

    // loop through each group of digits, make sure given digit is valid and then add it to out
    for (group=0;group<5;group++){
        out=out<<tensDigitBits[group]; 
        digit = date[group][0] - '0';
        if (!inRange(digit, 0, tensDigitMax[group])){
            return -1;
        }
        out = out | digit;
        
        out = out << 4;
        digit = date[group][1] - '0';
        out = out | digit; 


        // make sure month is valid
        if (group == 0){
            int month = (((out>>4)&0b1)*10)+(out&0b1111);
            if (!inRange(month,1,12)){
                return -1;
            }
        }
        // make sure day is valid in month
        if (group == 1){
            int month = ((out>>10)&0b1)*10+((out>>6)&0b1111);
            int day = ((out>>4)&0b1)*10+(out&0b1111);
            if (!inRange(day,1,maxDay[month-1])){
                return -1;
            }
        }
    }
    return out;
}

    

int main(){
    int nLines;
    scanf("%d",&nLines);
    int date;
    char input[5][2];
    // for nLines, get input and print compressed date or INVALID
    while (nLines>0){
        scanf("%2s%*c %2s%*c %2s%*c %2s%*c %2s",input[0],input[1],input[2],input[3],input[4]);  
        date=compressDate(input);
        if (date==-1){
            printf("INVALID\n");
        }
        else{
            printf("%d\n",date);
        }
        nLines--;
    }
    return 0;
}