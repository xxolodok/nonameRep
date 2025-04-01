CC = gcc
CFLAGS = -g

all: Array-basedStack_test

Array-basedStack.o: Array-basedStack.c Array-basedStack.h
	${CC} ${CFLAGS} -c Array-basedStack.c -o Array-basedStack.o

Array-basedStack_test.o: Array-basedStack_test.c Array-basedStack.h
	${CC} ${CFLAGS} -c Array-basedStack_test.c -o Array-basedStack_test.o

Array-basedStack_test: Array-basedStack_test.o Array-basedStack.o
	${CC} ${CFLAGS} -o Array-basedStack_test Array-basedStack_test.o Array-basedStack.o

test: Array-basedStack_test
	./Array-basedStack_test

check_fmt:
	clang-format -i *.c *.h

clean:
	rm -f *.o Array-basedStack_test

.PHONY: all test check_fmt clean
