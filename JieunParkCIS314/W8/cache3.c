#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

typedef struct {
    unsigned char valid;
    unsigned int tag;
    unsigned int value;   
} CacheLine;

void showBytes(byte_pointer start, int len) {
    for (int i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

unsigned getByte(unsigned value, int b){
    unsigned shift = b * 8;
    unsigned mask = (0xff << shift);
    unsigned bit = (value & mask) >> shift; 
    return bit;
}

void splitAddress(unsigned address, unsigned* addressParts){
    // Splits address into its 3 parts and sticks them into a unsignged array
    addressParts[0] = address >> 6;           // 26 tag bits
    addressParts[1] = (address << 26) >> 28;  // 4 set bits
    addressParts[2] = (address << 30) >> 30;  // 2 block/offset bits
}

void read(CacheLine* cache, unsigned address){
    //splitAddress(address, addressParts);
    int tagbit = address >> 6;
    int setbit = (address <<26) >> 28;
    int offset = (address <<30)>> 30;

    CacheLine line = cache[setbit];
    unsigned bitValue = getByte(line.value, offset);

    printf("looking for set: %x - tag: %x\n", setbit, tagbit);
    if (line.valid && tagbit == line.tag){
        printf("found set: %x - tag: %x - valid: %x - value: %x\n", setbit, line.tag, line.valid, bitValue);
        printf("hit!\n");
    } else {
        if (!line.valid){
            printf("miss! no valid set found\n");    
        } else {
            printf("found set: %x - tag: %x - valid: %x - value: %x\n", setbit, line.tag, line.valid, bitValue);
            printf("miss! tags do not match\n"); 
        }
    }
}

void write(CacheLine* cache, unsigned address, unsigned value){
    //splitAddress(address, addressParts);
    int tagbit = address >> 6; // tag
    int setbit = (address <<26) >> 28; // set bits
    CacheLine line = cache[setbit];
    if (line.valid){
        printf("evicting block - set: %x - tag: %x - valid: %x - value: ", setbit, line.tag, line.valid);
        showBytes((byte_pointer) &line.value, sizeof(unsigned));
    }
    
    printf("wrote set: %x - tag: %x - valid: %x - value: ", setbit, tagbit, 1);
    showBytes((byte_pointer) &value, sizeof(unsigned));
    cache[setbit].valid = 1;
    cache[setbit].tag = tagbit;
    cache[setbit].value = value;
}

void print(CacheLine* cache, int length){
    for (int i = 0; i < length; i++){
        CacheLine line = cache[i];
        if (line.valid){
            printf("set: %d - tag: %x - valid: %x - value: ", i, line.tag, line.valid);
            showBytes((byte_pointer) &line.value, sizeof(unsigned));
        }
    }   
}

int main(int argc, char const *argv[]){
    int length = 16;
    CacheLine* cache = malloc(length * sizeof(CacheLine));
    for (int i = 0; i < length; i++){
        cache[i].valid = 0;
    }
    
    //unsigned addressParts[3];

    char command;
    unsigned address;
    unsigned value;
    int proceed = 1;
    while (proceed){
        printf("%s", "Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        scanf("%s", &command);

        switch (command){
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
                print(cache, length);
                printf("\n");
                break;
            case 'q':
                proceed = 0;
                break;
        }  
    }

    return 0;
}