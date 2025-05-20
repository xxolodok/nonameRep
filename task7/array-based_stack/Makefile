CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: array-based_stack_test

array-based_stack.o: array-based_stack.c array-based_stack.h
	$(CC) $(CFLAGS) -c $< -o $@

array-based_stack_test.o: array-based_stack_test.c array-based_stack.h
	$(CC) $(CFLAGS) -c $< -o $@

array-based_stack.a: array-based_stack.o
	ar rc $@ $^

array-based_stack_test: array-based_stack_test.o array-based_stack.a
	$(CC) $(CFLAGS) -o $@ $^

test: array-based_stack_test
	./array-based_stack_test

clean:
	rm -f *.o *.a array-based_stack_test

.PHONY: all test clean

