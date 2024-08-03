
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tlbEntry {
    int tag;
    int PPN;
    struct tlbEntry * next;
};
struct cacheEntry {
    int tag;
    int * bytes;
};

int main(int argc, char *argv[]){
    char section[4];
    int vals[6];

    struct tlbEntry * tlb[4];
    int pageTable[16];
    struct cacheEntry * cache[16];
    int i;
    for (i=0;i<4;i++){
        tlb[i]=0;
    }
    for (i=0;i<16;i++){
        cache[i]=0;
    }
    
    FILE* fp=fopen(argv[1],"r");
    while (fscanf(fp,"%4s",section)>0){
        if (strcmp(section,"TLB,")==0){
            fscanf(fp,"%x,%x,%x\n",vals,vals+1,vals+2);
            struct tlbEntry * newEntry = malloc(sizeof (struct tlbEntry));
            *newEntry=(struct tlbEntry){vals[1],vals[2], tlb[vals[0]]};
            tlb[vals[0]]=newEntry;
        }
        if (strcmp(section,"Page")==0){
            fscanf(fp,",%x,%x\n",vals,vals+1);
            pageTable[vals[0]]=vals[1];
        }
        if (strcmp(section,"Cach")==0){
            fscanf(fp,"e,%x,%x,%x,%x,%x,%x\n",vals,vals+1,vals+2,vals+3,vals+4,vals+5);
            // int ** bytes = malloc(sizeof(int)*4);
            // *bytes=(int[]){vals[2],vals[3],vals[4],vals[5]};
            int * bytes = malloc(sizeof(int)*4);
            bytes[0]=vals[2];
            bytes[1]=vals[3];
            bytes[2]=vals[4];
            bytes[3]=vals[5];
            struct cacheEntry * newEntry = malloc(sizeof (struct cacheEntry));
            *newEntry=(struct cacheEntry){vals[1],bytes};
            // *newEntry=(struct cacheEntry){vals[1],*bytes};
            cache[vals[0]]=newEntry;
        };
    }
    int input;
    for (i=0;i<3;i++){
        printf("Enter Virtual Address:");
        scanf("%x",&input);
        if (input > pow(2,14)){
            printf("Can not be determined\n");
            continue;
        }

        int po = input&0b111111;
        int vpn = input>>6;
        int ti=vpn&0b11;
        int tt= vpn>>2;
        struct tlbEntry * tlbentry;
        int ppn = -1;
        // printf("\nti:%x",ti);
        // printf("\ntt:%x",tt);
        // printf("\npo:%x\n",po);
        for (tlbentry=tlb[ti];tlbentry!=0;tlbentry=tlbentry->next){
            if (tlb[ti]->tag==tt){
                ppn=tlbentry->PPN;
                break;
            }
        }
        
        // printf("ppn:%x\n",ppn);
        if (ppn==-1){
            // printf("went to page table");
            ppn=pageTable[vpn&0b1111];
        }
        // printf("ppn:%x\n",ppn);
        int co=po&0b11;
        int ci=po>>2;
        
        // printf("co:%x\n",co);
        // printf("ci:%x\n",ci);
        // printf("tag:%x\n",cache[ci]->tag);
        if (cache[ci]!=0 && cache[ci]->tag==ppn){
            printf("found byte:%x\n",(cache[ci]->bytes)[co]);
        }
        else{
            printf("Can not be determined\n");
        }
    }


    return 0;
}