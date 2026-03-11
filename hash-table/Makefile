CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

all: hash_basics

hash_basics: hash_basics.c
	$(CC) $(CFLAGS) hash_basics.c -o hash_basics

run: hash_basics
	./hash_basics

clean:
	rm -f hash_basics
	rm -rf hash_basics.dSYM

.PHONY: all run clean
