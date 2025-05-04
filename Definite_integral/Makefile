CC = gcc
CFLAGS = -g

all: test_definite_integral

definite_integral.o: definite_integral.c definite_integral.h
	${CC} ${CFLAGS} -c definite_integral.c -o definite_integral.o

test_definite_integral.o: test_definite_integral.c definite_integral.h
	${CC} ${CFLAGS} -c test_definite_integral.c -o test_definite_integral.o

definite_integral.a: definite_integral.o
	ar rc definite_integral.a definite_integral.o

test_definite_integral: test_definite_integral.o definite_integral.a
	${CC} ${CFLAGS} -o test_definite_integral test_definite_integral.o definite_integral.a

test: test_definite_integral
	./test_definite_integral

clean:
	rm -f *.o *.a test_definite_integral

.PHONY: all test clean