CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99 -pedantic
LDFLAGS = -lm
AR = ar
ARFLAGS = rcs

SRC = definite_integral.c
OBJ = definite_integral.o
LIB = libdefinite_integral.a
TEST_SRC = test_definite_integral.c
TEST_OBJ = test_definite_integral.o
TEST_BIN = test_definite_integral

all: $(LIB) $(TEST_BIN)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(TEST_OBJ): $(TEST_SRC) definite_integral.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(SRC) definite_integral.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(TEST_OBJ) $(LIB)
	$(CC) $(CFLAGS) $^ -L. -ldefinite_integral $(LDFLAGS) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_BIN) $(LIB)
