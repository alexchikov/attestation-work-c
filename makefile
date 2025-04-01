CC=gcc
CFLAGS=-c -Wall

all: clean main

main: main.c
	$(CC) $(C_FLAGS) main.c lib/*.c -o bin/main

clean:
	rm -rf bin/main
	rm -rf bin/*.o
	rm -rf out/*