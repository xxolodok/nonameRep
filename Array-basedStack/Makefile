CC = gcc

all: Array-basedStack_test

Array-basedStack.o: Array-basedStack.h Array-basedStack.c
	@${CC} -g -c Array-basedStack.c -o Array-basedStack.o

Array-basedStack.a: Array-basedStack.o
	@ar rc Array-basedStack.a Array-basedStack.o

Array-basedStack_test.o: Array-basedStack_test.c
	@${CC} -g -c Array-basedStack_test.c -o Array-basedStack_test.o

Array-basedStack_test: Array-basedStack_test.o Array-basedStack.a
	@${CC} -g -static -o Array-basedStack_test Array-basedStack_test.o Array-basedStack.a

test: Array-basedStack_test
	@./*_test

.PHONY: all
