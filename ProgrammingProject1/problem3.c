// implement your program here
#include <stdint.h>
#include <stdio.h>

struct ab{
    int a;
    int b;
};
// reverses the bits of the given number. Disregards leading zeros.
// @param n: the number to reverse
// @return: the reversed number
int reverseBits(int n){
    int out=0;
    while (n!=0){
        out = out << 1;
        out=out |(n & 0b1);
        n=n>>1;
    }
    return out;
}
// gets the bit length of the given number
// @param n: the number
// @return: the length of the given number
int bitLength(int n){
    int out=0;
    while (n!=0){
        out++;
        n=n>>1;
    }
    return out;
}


// checks where the given number has an odd number of '1' bits
// @param n: the number
// @return: 1 if the given number has an odd number of '1' bits, 0 otherwise
int oddOnes(int n){
    int out=0;
    while (n!=0){
        out=out^(n&0b1);
        n=n>>1;
    }
    return out;
}

// gets a and b from the given number as specified by the assignment
// @param n: the number
// @return: struct ab where a and b are assigned as specified by assignment
struct ab getAB(int n){
    // loop through n's bits in reverse, appending a "1" to a or b as necessary
    // for this, we need the bitlength of the number (to know when to stop looping in reverse),
    // whether n is odd or even (to know if to start by appending 1 to a or b),
    // and the representation of n with bits reversed
    int len = bitLength(n);
    int oddIndex = oddOnes(n); 
    n = reverseBits(n);
    int a=0;
    int b=0;
    int lastbit;
    while (len>0){
        a=a << 1;
        b=b << 1;
        lastbit=n&0b1;
        // if currently at an odd numbered 1 (i1,i3,...), a should have its last bit
        // assigned n's last bit.
        if (oddIndex){
            a=(a | lastbit);
        }
        // else b's last bit should be assigned n's last bit
        else {
            b=(b | lastbit);
        }
        oddIndex=oddIndex^lastbit;  //if lastbit was one, change from odd numered i to even numbered i
        n=n >> 1;
        len--;
    }
    struct ab out = {a,b};
    return out;
}
int main(){
    int input=1;
    struct ab out;
    scanf("%d",&input);
    // reads numbers and prints corresponding a and b until reaches a 0
    while (input!=0){
        out = getAB(input);
        printf("%d %d\n", out.a,out.b);
        scanf("%d",&input);
    }
    return 0;
}

