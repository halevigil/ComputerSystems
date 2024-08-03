#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include <sys/time.h>
#include <math.h>
// returns 1 if the sum of the digits in n > 9, 0 otherwise
int sumGreaterThan9(int n){
    int s=0;
    while (n>0){
        s+=n%10;
        n/=10;
    }
    return s>9;
}
// returns the number of primes with sum > 9 in range [start, end]
void getPrimes(int start, int end, char fileName[]){
    int n;
    int i;
    int isPrime;
    FILE * out=fopen(fileName,"w");
    fclose(out);
    for (n=start;n<=end;n++){
        if (sumGreaterThan9(n)!=0){
            continue;
        }
        isPrime=1;
        for (i=2;i<n;i++){
            if (n%i==0){
                isPrime=0;
                break;
            }
        }
        if (isPrime==0){
            continue;
        }
        out = fopen(fileName,"a");
        fprintf(out,"%d\n",n);
        fclose(out);
    }
}

int main(int argc, char *argv[]){
    int i;
    int pid;
    int waitOut;
    FILE * out;
    FILE * out1;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    getPrimes(1,100000,"primes_control_run");

    gettimeofday(&end, 0);
    float time_elapsed = end.tv_sec - begin.tv_sec + 1e-6*(end.tv_usec - begin.tv_usec);
    out = fopen("primes_control_run","a");
    fprintf(out,"time elapsed:%f\n",time_elapsed);
    fclose(out);


    gettimeofday(&begin, 0);
    for (i=0;i<10;i++){
        pid = fork();
        char s[9];
        if (pid==0){
            sprintf(s,"primes%d",i);
            getPrimes((i*10000)+1,i*10000+10000, s);
            exit(0);
        }
    }
    for (i=0;i<10;i++){
        wait(&waitOut);
    }
    out1=fopen("primes","w");
    for (i=0;i<10;i++){
        char s[9];
        sprintf(s,"primes%d",i);
        out=fopen(s,"r");
        char c;
        while (1){
            c = fgetc(out);
            if (c==EOF){
                break;
            }
            fputc(c,out1);
        }
    }
    gettimeofday(&end, 0);
    time_elapsed = end.tv_sec - begin.tv_sec + 1e-6*(end.tv_usec - begin.tv_usec);
    fprintf(out1,"time elapsed:%f\n",time_elapsed);
    fclose(out1);
}