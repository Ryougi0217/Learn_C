CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wconversion -pedantic

app: main.o greet.o
	$(CC) $(CFLAGS) main.o greet.o -o app

main.o: main.c greet.h
	$(CC) $(CFLAGS) -c main.c

greet.o: greet.c greet.h
	$(CC) $(CFLAGS) -c greet.c

.PHONY: clean
clean:
	# TODO：删除 app、main.o 和 greet.o

