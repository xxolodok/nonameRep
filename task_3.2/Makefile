CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11 -Ipool_allocator

all: ref_count_test

pool_allocator.o: pool_allocator/pool_allocator.c pool_allocator/pool_allocator.h
	$(CC) $(CFLAGS) -c pool_allocator/pool_allocator.c -o pool_allocator.o

ref_count.o: ref_count/ref_count.c ref_count/ref_count.h pool_allocator/pool_allocator.h
	$(CC) $(CFLAGS) -c ref_count/ref_count.c -o ref_count.o

ref_count_test.o: ref_count/ref_count_test.c ref_count/ref_count.h pool_allocator/pool_allocator.h
	$(CC) $(CFLAGS) -c ref_count/ref_count_test.c -o ref_count_test.o

ref_count.a: ref_count.o
	ar rc ref_count.a ref_count.o

ref_count_test: ref_count_test.o ref_count.a pool_allocator.o
	$(CC) $(CFLAGS) -o ref_count_test ref_count_test.o ref_count.a pool_allocator.o

test: ref_count_test
	./ref_count_test

format:
	clang-format -i pool_allocator/*.c pool_allocator/*.h ref_count/*.c ref_count/*.h

check-format:
	clang-format --dry-run --Werror pool_allocator/*.c pool_allocator/*.h ref_count/*.c ref_count/*.h

clean:
	rm -f *.o *.a ref_count_test

.PHONY: all test clean format check-format
