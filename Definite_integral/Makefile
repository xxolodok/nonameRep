TARGET = test_definite_integral
LIBNAME = definiteintegral
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99 -pedantic

LIBSOURCE  = definite_integral.c
TESTSOURCE = test_definite_integral.c
HEADERS    = definite_integral.h

LIBOBJS  = $(LIBSOURCE:.c=.o)
TESTOBJS = $(TESTSOURCE:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

lib$(LIBNAME).a: $(LIBOBJS)
	ar rcs $@ $^

$(TARGET): $(TESTOBJS) lib$(LIBNAME).a
	$(CC) $(CFLAGS) $(TESTOBJS) -L. -l$(LIBNAME) -lm -o $@

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(LIBOBJS) $(TESTOBJS) lib$(LIBNAME).a $(TARGET)

rebuild: clean all

check_fmt:
	clang-format -n --style=Google $(LIBSOURCE) $(TESTSOURCE) $(HEADERS)
