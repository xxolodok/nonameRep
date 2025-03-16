CC = gcc
CFLAGS = -g

all: Array-basedStack_test

Array-basedStack.o: Array-basedStack.c Array-basedStack.h
	${CC} ${CFLAGS} -c Array-basedStack.c -o Array-basedStack.o

Array-basedStack_test.o: Array-basedStack_test.c Array-basedStack.h
	${CC} ${CFLAGS} -c Array-basedStack_test.c -o Array-basedStack_test.o

Array-basedStack.a: Array-basedStack.o
	ar rc Array-basedStack.a Array-basedStack.o

Array-basedStack_test: Array-basedStack_test.o Array-basedStack.a
	${CC} ${CFLAGS} -o Array-basedStack_test Array-basedStack_test.o Array-basedStack.a

test: Array-basedStack_test
	./Array-basedStack_test

clean:
	rm -f *.o *.a Array-basedStack_test

.PHONY: all test clean
