CC = gcc
CFLAGS = -g

all: Linked_List_test

Linked_List.o: Linked_List.c Linked_List.h
	${CC} ${CFLAGS} -c Linked_List.c -o Linked_List.o

Linked_List_test.o: Linked_List_test.c Linked_List.h
	${CC} ${CFLAGS} -c Linked_List_test.c -o Linked_List_test.o

Linked_List.a: Linked_List.o
	ar rc Linked_List.a Linked_List.o

Linked_List_test: Linked_List_test.o Linked_List.a
	${CC} ${CFLAGS} -o Linked_List_test Linked_List_test.o Linked_List.a

test: Linked_List_test
	./Linked_List_test

clean:
	rm -f *.o *.a Linked_List_test

.PHONY: all test clean
