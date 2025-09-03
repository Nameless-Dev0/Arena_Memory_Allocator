#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include "arena.h"

int main(){

    int alloc_size = 32;    
    uint8_t* stored_text = (uint8_t*)alloc(alloc_size);
    if(stored_text == NULL){
        printf("Arena memory allocation failed...\n");
        exit(-1);
    }
    
    uint8_t counter = 0; // 0 -> 255
    for (int i = 0; i < alloc_size; i++)
        stored_text[i] = counter++;
    
    for (int i = 0; i < alloc_size; i++)
        printf("At address (%p) : %hhu\n", (void*)&stored_text[i], stored_text[i]);
    
    afree(&stored_text);

    for (int i = 0; i < alloc_size; i++)
        printf("After free, address (%p) : %hhu\n", &stored_text[i], stored_text[i]); // AddressSanitizer exits the program.

    return 0;
}