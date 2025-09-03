#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define ARENA_SIZE 10240 // 10 KB 

uint8_t *alloc(int bytes);
void     afree(uint8_t** block);


#endif //ARENA_H