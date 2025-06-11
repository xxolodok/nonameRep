CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS =

SOURCES = IAllocator.c ArrayList.c ArrayListTests.c
HEADERS = IAllocator.h ArrayList.h
OBJECTS = $(SOURCES:.c=.o)

CLANG_FORMAT = clang-format
FORMAT_FILES = $(SOURCES) $(HEADERS)

.PHONY: all clean format check_fmt test

all: ArrayListTests

ArrayListTests: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) ArrayListTests

format:
	$(CLANG_FORMAT) -i $(FORMAT_FILES)

check_fmt:
	@echo "Checking code format..."
	@$(CLANG_FORMAT) --dry-run --Werror $(FORMAT_FILES)

test: ArrayListTests
	./ArrayListTests