#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include "arena.h"

int main(){

    char* stored_text = (char*)alloc(ARENA_SIZE+1);
    if(stored_text == NULL){
        printf("Arena memory allocation failed...\n");
        exit(-1);
    }

    return 0;
}