CC=gcc
CFLAGS=-c -Wall

all: clean main

main: main.c
	$(CC) $(C_FLAGS) main.c lib/*.c -o bin/main

clean:
	rm -rf main
	rm -rf *.o