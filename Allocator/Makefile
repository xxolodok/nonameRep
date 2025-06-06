CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SOURCES = IAllocator.c ArrayList.c ArrayListTests.c
HEADERS = IAllocator.h ArrayList.h
OBJECTS = $(SOURCES:.c=.o)

all: ArrayListTests

ArrayListTests: $(OBJECTS)	
	$(CC) $(LDFLAGS) $(OBJECTS) -o ArrayListTestsm	
	%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@	

clean:	
	rm -f $(OBJECTS) ArrayListTests	