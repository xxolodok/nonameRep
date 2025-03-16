CC = gcc

all: Linked_List_test

Linked_List.o: Linked_List.h Linked_List.c
	${CC} -g -c Linked_List.c -o Linked_List.o

Linked_List.a: Linked_List.o
	ar rc Linked_List.a Linked_List.o

Linked_List_test.o: Linked_List_test.c
	${CC} -g -c Linked_List_test.c -o Linked_List_test.o

Linked_List_test: Linked_List_test.o Linked_List.a
	${CC} -g -static -o Linked_List_test Linked_List_test.o Linked_List.a

test: Linked_List_test
	./Linked_List_test

.PHONY: all test
