CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rc
FORMAT = clang-format

all: stack_test

array-based_stack.o: array-based_stack.c array-based_stack.h
	$(CC) $(CFLAGS) -c $< -o $@

array-based_stack_test.o: array-based_stack_test.c array-based_stack.h
	$(CC) $(CFLAGS) -c $< -o $@

libstack.a: array-based_stack.o
	$(AR) $(ARFLAGS) $@ $^

stack_test: array-based_stack_test.o libstack.a
	$(CC) $(CFLAGS) -o $@ $^

test: stack_test
	./stack_test

format:
	$(FORMAT) -i *.c *.h

check-format:
	$(FORMAT) --dry-run --Werror *.c *.h

clean:
	rm -f *.o *.a stack_test

.PHONY: all test format check-format clean