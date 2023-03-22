# Makefile
CC = gcc
CFLAGS = -Wall -Wextra

all: hello

hello: hello.o 
	$(CC) $(CFLAGS) -o hello hello.c

clean:
	rm -f hello hello.o main.o
