#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


struct Cache{
	int valid[16];
    //26-bit
    unsigned int tag[16];
    //4-byte
    unsigned value[16];
};

struct Cache createCache()
{	
	struct Cache mycache;


	for(int i=0; i<16; i++){
		mycache.valid[i]=0;
		mycache.tag[i]=0;
		mycache.value[i]=0;
	}
	


	return mycache;


}
struct Cache write(struct Cache cache, unsigned address, unsigned value){
	unsigned int dec;
	unsigned thing=address>>2;
	

	if(cache.valid[thing] !=1){
		if(thing>>3 <1)
			cache.tag[thing]=0;
		else 
			cache.tag[thing]=1;
		cache.valid[thing]=1;
		cache.value[thing]=value;
		printf("wrote set index %d, tag: %d, writting value %x\n", thing, cache.tag[thing],value);
		//print out new value
	}
	else{
		printf("evicting block %d, tag: %d, removing value %x\n", thing, cache.tag[thing], cache.value[thing]);
		cache.value[thing]=value;
		printf("wrote set index %d, tag: %d, writting value %x\n", thing, cache.tag[thing], value);
	}
	return cache;

}
void read(struct Cache cache, unsigned address){
	unsigned thing=address>>2;
	if(cache.valid[thing] !=1){
		printf("set index %d\n, tag: %d\n", thing, cache.tag);
		printf("Miss");
	}
	else{
		printf("set index %d, tag: %d\n", thing, cache.tag);
		printf("Hit! Value: %x\n", cache.value[thing]);
	}

}
void print(struct Cache cache){
	for(int i=0; i<17; i++){
		if(cache.valid[i]==1){
			printf("set index %d, tag: %d, value: %x\n", (i), cache.tag[i], cache.value[i] );
		}
	}
}



int main() {
	struct Cache mycache =createCache();
	int done=0;
	while(done==0){
	  //char* cha = malloc(sizeof(cha));                                                                                                                                                                          

	  printf("Enter r for read, w for write, p to print, q to quit: ");                                                                                                                                                                
	  char input;
	  scanf ("%c", &input); 
	   switch (input){
            case 'r' : printf("You chose r\n");
			            //read, find a value
			            unsigned address;
			            unsigned value;

			            printf("Enter 32-bit unsigned hex address:");
			            scanf("%x", &address);
			            read(mycache, address);
			            //call read

                       break;

            case 'w' : printf("You chose w\n");
			            //print the	set index, tag,	and	value of the	
						//new block	being written
			            unsigned address2;
			            unsigned value2;

			            printf("Enter 32-bit unsigned hex address: ");
			            scanf("%x", &address2);
			            //adress looks like xbbcc, 2 value hex
			            printf("Enter 32-bit unsigned hex value: ");

			            scanf("%x", &value2);
			            mycache=write(mycache, address2, value2);
			            //writeToCache(myCache, address, value);
                       break;

            case 'p': printf("You chose p\n");
            //print out the current cache
            			print(mycache);
            			break; 
            case 'q' : 
            printf("You chose q\n");
            			done=1;
                    	break;
            }



	  //printf("Entery not valid, You entered: %c\n", input); 
	   }   
	   return 0;                                                                                                                                                      
}