TARGET = test_definite_integral

LIBNAME = definiteintegral


CC = gcc

CFLAGS = -Wall -Wextra -g -std=c99

LIBOBJS = definite_integral.o
TESTOBJS = test_definite_integral.o

LIBSOURCE = definite_integral.c
TESTSOURCE = test_definite_integral.c

HEADERS = definite_integral.h

$(LIBOBJS): $(LIBSOURCE) $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

lib$(LIBNAME).a: $(LIBOBJS)
	ar rcs lib$(LIBNAME).a $(LIBOBJS)

$(TESTOBJS): $(TESTSOURCE) $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(TESTOBJS) lib$(LIBNAME).a
	$(CC) $(CFLAGS) $(TESTOBJS) -L. -l$(LIBNAME) -lm -o $(TARGET)

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(LIBOBJS) $(TESTOBJS) lib$(LIBNAME).a $(TARGET)

rebuild: clean all
