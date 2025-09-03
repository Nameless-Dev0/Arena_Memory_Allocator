#include "arena.h"

static uint8_t  alloc_buffer[ARENA_SIZE] = {0};
static uint8_t* alloc_position = alloc_buffer;

static bool is_enough_space(int requested_size);
static inline bool is_block_in_arena(uint8_t * block);

uint8_t *alloc(int bytes){
    if(!is_enough_space(bytes))
        return NULL;
    alloc_position += bytes;
    return alloc_position - bytes;
}

void afree(uint8_t** block){
    if(is_block_in_arena(*block)){
        memset(*block, '\0', (alloc_position - *block));
        alloc_position = *block;
        *block = NULL;
    }
}

static bool is_enough_space(int requested_size){
    int remaining_size = (alloc_buffer + ARENA_SIZE) - alloc_position;
    return remaining_size >= requested_size;
}

static inline bool is_block_in_arena(uint8_t * block){
    return (alloc_buffer + ARENA_SIZE > block && block >= alloc_buffer);
}
