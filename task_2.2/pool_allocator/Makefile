CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

all: pool_allocator_test

pool_allocator.o: pool_allocator.c pool_allocator.h
	$(CC) $(CFLAGS) -c pool_allocator.c -o pool_allocator.o

pool_allocator_test.o: pool_allocator_test.c pool_allocator.h
	$(CC) $(CFLAGS) -c pool_allocator_test.c -o pool_allocator_test.o

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	$(CC) $(CFLAGS) -o pool_allocator_test pool_allocator_test.o pool_allocator.a

test: pool_allocator_test
	./pool_allocator_test

format:
	clang-format -i *.c *.h

check-format:
	clang-format --dry-run --Werror *.c *.h

clean:
	rm -f *.o *.a pool_allocator_test

.PHONY: all test clean format check-format
