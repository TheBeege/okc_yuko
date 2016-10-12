CC=gcc
CFLAGS=-I. -pthread
DG=gdb

all: clean okc

okc: main.c
	$(CC) $(CFLAGS) -o okc.out main.c

debug: main.c
	$(CC) $(CFLAGS) -pthread main.c -g
	$(DG) ./a.out

.PHONY: clean

clean:
	rm okc
