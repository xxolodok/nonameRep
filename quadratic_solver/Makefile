CC = gcc
CFLAGS = -g
LDFLAGS = -lm

all: quadratic_test

quadratic.o: quadratic.c quadratic.h
	$(CC) $(CFLAGS) -c quadratic.c -o quadratic.o

quadratic.a: quadratic.o
	ar rc quadratic.a quadratic.o

quadratic_test.o: quadratic_test.c quadratic.h
	$(CC) $(CFLAGS) -c quadratic_test.c -o quadratic_test.o

quadratic_test: quadratic_test.o quadratic.a
	$(CC) $(CFLAGS) -o quadratic_test quadratic_test.o quadratic.a $(LDFLAGS)

clean:
	rm -f quadratic_test quadratic_test.o quadratic.o quadratic.a

.PHONY: all clean
