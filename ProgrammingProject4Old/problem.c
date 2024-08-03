
#include <string.h>
#include <stdio.h>
#include <math.h>

struct tlbEntry {
    int tag;
    int PPN;
    struct tlbEntry * next;
};
struct cacheEntry cacheEntry {
    int tag;
    int bytes[];
    struct cacheEntry * next;
};

int main(){
    char* section="";
    int vals[6];

    int maxTLB=0;
    int maxVPN=0;
    int maxCache=0;

    // first scan to determine how big you need to make the TLB, page table, and cache arrays
    while (scanf("%4s",section)!=NULL){
        if (strcmp(section,"TLB,")==0){
            scanf("%x,%x,%x\n",vals,vals+1,vals+2);
            maxTLB=max(vals[0],maxTLB);
        }
        if (strcmp(section,"Page")==0){
            scanf(",%x,%x,%x\n",vals,vals+1);
            maxVPN=max(vals[0],maxVPN);
        }
        if (strcmp(section,"Cach")==0){
            scanf("e,%x,%x,%x,%x,%x,%x\n",vals,vals+1,vals+2,vals+3,vals+4,vals+5);
            maxCache=max(maxCache,vals);
        }
        if (strcmp(section,"DONE")==0){
            break;
        }
    }

    int tlbBits = (int)(log2((double) maxTLB))+1;
    int pageBits = (int) (log2((double) maxVPN))+1;
    int cacheBits = (int) (log2((double) maxTLB))+1;
    struct tlbEntry * tlb[maxTLB];
    int pagetable[maxVPN];
    struct cacheEntry * cache[maxTLB];
    int i;
    // initiali
    for (i=0;i<maxTLB;i++){
        tlb[i]=-1;
    }
    for (i=0;i<maxVPN;i++){
        pagetable[i]=-1;
    }
    for (i=0;i<maxCache;i++){
        cache[i]=-1;
    }
    //second scan to fill the tlb, page table, and bache arrays
    rewind(stdin);
    while (scanf("%4s",section)!=NULL){
        if (strcmp(section,"TLB,")==0){
            scanf("%x,%x,%x\n",vals,vals+1,vals+2);
            tlb[vals[0]]=(struct tlbEntry *){vals[0],vals[1], tlb[vals[0]]};
        }
        if (strcmp(section,"Page")==0){
            scanf(",%x,%x,%x\n",vals,vals+1);
            pagetable[vals[0]]=vals[1];
        }
        if (strcmp(section,"Cach")==0){
            scanf("e,%x,%x,%x,%x,%x,%x\n",vals,vals+1,vals+2,vals+3,vals+4,vals+5);
            int bytes[4]=(int*){vals[2],vals[3],vals[4],vals[5]};
            cache[vals[0]]=(struct cacheEntry *){vals[1],bytes,cache[vals[0]]};
        }
        if (strcmp(section,"DONE")==0){
            break;
        }
    }

    int input;
    int j;
    int validBits;
    int validBits2;
    for (i=0;i<3;i++){
        printf("Enter Virtual Address:");
        scanf("%x",&input);
        struct tlbEntry * entry;
        // if (entry >0 | entry )
        validBits=0;
        for (j=0;i<cacheBits+2;j++){
            validBits=(validBits<<1)+1;
        }
        int po = input&validBits;
        
        validBits2=0;
        for (j=0;i<pageBits+2;j++){
            validBits2=(validBits2<<1)+1;
        }
        int vpn = (input>>(validBits+2))&validBits2;
        // int tlb
        for (entry=0)
    }


    return 0;
}