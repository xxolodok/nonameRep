CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rc
FORMAT = clang-format

all: linked_list_test

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

linked_list_test.o: linked_list_test.c linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

linked_list.a: linked_list.o
	$(AR) $(ARFLAGS) $@ $^

linked_list_test: linked_list_test.o linked_list.a
	$(CC) $(CFLAGS) -o $@ $^

test: linked_list_test
	./linked_list_test

format:
	$(FORMAT) -i *.c *.h

check-format:
	$(FORMAT) --dry-run --Werror *.c *.h

clean:
	rm -f *.o *.a linked_list_test

.PHONY: all test format check-format clean
