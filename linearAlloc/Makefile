CC = gcc
CFLAGS = -g
LDFLAGS = -lm

all: linearAlloc_test

linearAlloc.o: linearAlloc.c linearAlloc.h
	$(CC) $(CFLAGS) -c linearAlloc.c -o linearAlloc.o

linearAlloc.a: linearAlloc.o
	ar rc linearAlloc.a linearAlloc.o

linearAlloc_test.o: linearAlloc_test.c linearAlloc.h
	$(CC) $(CFLAGS) -c linearAlloc_test.c -o linearAlloc_test.o

linearAlloc_test: linearAlloc_test.o linearAlloc.a
	$(CC) $(CFLAGS) -o linearAlloc_test linearAlloc_test.o linearAlloc.a $(LDFLAGS)

clean:
	rm -f linearAlloc_test linearAlloc_test.o linearAlloc.o linearAlloc.a

.PHONY: all clean

