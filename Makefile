CC = gcc
CFLAGS = -fsanitize=address -fno-omit-frame-pointer -O1 -Wall -Wextra -Iinclude -g

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
HEADER = $(wildcard include/*.h)

TARGET = build/arena_allocator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*
