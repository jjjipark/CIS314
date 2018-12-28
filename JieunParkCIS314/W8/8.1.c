#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *pointer;

typedef struct {
    unsigned char valid;
    unsigned int tag; //26 bits
    unsigned int value;   //4bits
} Cache;                                // get an idea from Zach

void printBytes(pointer value) {
    for (int i = 0; i < 4; i++)
        printf(" %02x", value[i]);
    printf("\n");
}


void write(Cache* cache, unsigned address, unsigned value){
    unsigned tagbit = address >> 6; // tag
    unsigned setbit = (address <<26) >> 28; // set bits
    //unsigned setbit = address >>2

    Cache mycache = cache[setbit];  //get cache of specific set

    if (mycache.valid==1){
        printf("evicting block - set: %x - tag: %x - valid: 1 - value: ", setbit, mycache.tag);
        printBytes(&mycache.value);
        printf("wrote set: %x - tag: %x - valid: 1 - value: ", setbit, tagbit);
        printBytes(&value);
     
    }else{
        printf("wrote set: %x - tag: %x - valid: 1 - value: ", setbit, tagbit);  
        printBytes(&value);
    }
    cache[setbit].valid = 1;
    cache[setbit].tag = tagbit;
    cache[setbit].value = value;        //add information to corresponding sets
}

void read(Cache* cache, unsigned address){
    unsigned tagbit = address >> 6;         //26 bits
    unsigned setbit = (address <<26) >> 28; //4bits
    //unsigned setbit = address >>2
    unsigned offset = (address <<30)>> 30;  //2bits

    Cache mycache = cache[setbit];

    //get value of mycache
    unsigned mask = (0xff << offset*8);
    unsigned value = (mycache.value & mask) >> offset*8;

    printf("looking for set: %x - tag: %x\n", setbit, tagbit);
    if (mycache.valid==1 ){
        if (tagbit == mycache.tag){
            printf("found set: %x - tag: %x - valid: 1 - value: %x\n", setbit, mycache.tag, value);
            printf("hit!\n");
        }else{
            printf("found set: %x - tag: %x - valid: 1 - value: %x\n", setbit, mycache.tag, value);
            printf("miss! tags don't match.\n"); 
        }
    }else {
        printf("miss! no valid set found\n");    
    }
}


void print(Cache* cache){
    for (int i = 0; i < 16; i++){
        Cache mycache = cache[i];
        if (mycache.valid == 1){
            printf("set: %d - tag: %x - valid: %x - value: ", i, mycache.tag, mycache.valid);
            printBytes(&mycache.value);
        }
    }   
}

//void newCache(){
//    Cache* cache = malloc(16* sizeof(Cache));
//    for (int i=0; i <16; i++){
//        cache[i].valid=0;
//    }
//}

int main(){

    Cache* cache = malloc(16 * sizeof(Cache)); //declare size of the cache
    for (int i = 0; i < 16; i++){
        cache[i].valid = 0;     //initialize valid value to 0 
    }
    
    unsigned address;
    unsigned value;
    int done = 0;
    while (done==0){
        printf("%s", "Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        char input;
        scanf("%s", &input);
        switch (input){
            case 'r':
                printf("%s", "Enter 32-bit unsigned hex address: "); 
                scanf("%x", &address);
                read(cache, address);
                printf("\n");
                break;
            case 'w':
                printf("%s", "Enter 32-bit unsigned hex address: "); 
                scanf("%x", &address);
                printf("%s", "Enter 32-bit unsigned hex value: "); 
                scanf("%x", &value);
                write(cache, address, value);
                printf("\n");
                break;
            case 'p':
                print(cache);
                printf("\n");
                break;
            case 'q':
                done = 1;
                break;
        }  
    }
    return 0;
}