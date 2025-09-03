# Arena Allocator

A simple fixed-size memory arena allocator implemented in C.

## Overview

This project provides a basic memory allocator that manages a fixed-size buffer (10 KB) for non-heap dynamic memory allocation. It supports allocating and freeing memory blocks within the arena stored in .bss segement.

## Features

- Fixed-size memory arena of 10 KB.
- Simple `alloc` function to allocate memory.
- Simple `afree` function to free memory by resetting the allocation pointer.
- Checks for available space before allocation.

## Files

- `include/arena.h` - Header file defining the allocator interface and constants.
- `src/arena.c` - Implementation of the arena allocator functions.
- `src/main.c` - Example usage of the allocator.
- `Makefile` - Build instructions.

## Usage

1. Include `arena.h` in your project.
2. Use `alloc(int bytes)` to allocate memory from the arena.
3. Use `afree(uint8_t* block)` to free memory by resetting the allocation pointer.

Example:

```c
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* buffer = (char*)alloc(1024);
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return -1;
    }
    // Use buffer...
    afree(buffer);
    return 0;
}