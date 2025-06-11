CC = gcc
CFLAGS = -Wall -Wextra -g

SOURCES = ArrayList.c ArrayListTests.c IAllocator.c
HEADERS = ArrayList.h IAllocator.h
OBJECTS = $(SOURCES:.c=.o)

TARGET = arraylist_test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

format:
	clang-format -i *.c *.h

check-format:
	clang-format --dry-run --Werror *.c *.h

.PHONY: all test clean format check-format
