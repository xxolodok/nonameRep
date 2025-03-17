CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99 -pedantic

TARGET = test_definite_integral
LIBNAME = definiteintegral
LIBOBJS = definite_integral.o
TESTOBJS = test_definite_integral.o
HEADERS = definite_integral.h

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

lib$(LIBNAME).a: $(LIBOBJS)
	ar rcs $@ $^

$(TARGET): $(TESTOBJS) lib$(LIBNAME).a
	$(CC) $(CFLAGS) $(TESTOBJS) -L. -l$(LIBNAME) -lm -o $@

all: $(TARGET)

test: $(TARGET)
	./$(TARGET)

check_fmt:
	clang-format -n --style=Google *.c *.h

clean:
	rm -f $(LIBOBJS) $(TESTOBJS) lib$(LIBNAME).a $(TARGET)

rebuild: clean all
