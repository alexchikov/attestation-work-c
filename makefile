CC=gcc
CFLAGS=-Wall

all: clean main

main: main.c
	$(CC) $(CFLAGS) main.c lib/*.c -o bin/main

clean:
	rm -rf bin/main
	rm -rf bin/*.o
	rm -rf out/*
