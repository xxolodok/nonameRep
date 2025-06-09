CC = gcc
CFLAGS = -g

all: array-based_stack_test

array-based_stack.o: array-based_stack.c array-based_stack.h
	${CC} ${CFLAGS} -c array-based_stack.c -o array-based_stack.o

array-based_stack_test.o: array-based_stack_test.c array-based_stack.h
	${CC} ${CFLAGS} -c array-based_stack_test.c -o array-based_stack_test.o

array-based_stack.a: array-based_stack.o
	ar rc array-based_stack.a array-based_stack.o

array-based_stack_test: array-based_stack.o array-based_stack_test.o array-based_stack.a
	${CC} ${CFLAGS} -o $@ array-based_stack_test.o array-based_stack.a

test: array-based_stack_test
	./array-based_stack_test

clean:
	rm -f *.o *.a array-based_stack_test

format:
	clang-format -i *.c *.h

check-format:
	clang-format --dry-run --Werror *.c *.h

.PHONY: all test clean

