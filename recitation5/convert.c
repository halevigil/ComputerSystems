#include <math.h>
#include <stdio.h>
void calculateBlocks(int cache_size, int address_length, int block_size, int associativity){
    int offset=log2(block_size);
    int set_index=log2(cache_size/associativity/block_size);
    int tag_size = address_length-offset-set_index;
    printf("offset:%d",offset);
    printf("set_index:%d",offset);
    printf("tag_size:%d",offset);
}