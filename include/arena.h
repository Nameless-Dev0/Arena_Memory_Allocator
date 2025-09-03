#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define ARENA_SIZE 10240 // 10 KB 

static uint8_t  alloc_buffer[ARENA_SIZE] = {0};
static uint8_t* alloc_position = alloc_buffer;

static bool is_enough_space(int requested_size);
static inline bool is_block_in_arena(uint8_t * block);

uint8_t *alloc(int bytes);
void     afree(uint8_t* block);


#endif //ARENA_H