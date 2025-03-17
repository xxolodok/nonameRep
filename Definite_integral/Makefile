CC=gcc
CFLAGS=-Wall -Werror
TEST_FLAGS=-lcheck

SRC=definite_integral.c test_definite_integral.c
OBJ=$(SRC:.c=.o)
EXEC=definite_integral
TEST_EXEC=test_definite_integral

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test: $(OBJ)
	gcc $(OBJ) -o $(TEST_EXEC) test_definite_integral.c $(TEST_FLAGS)
	./$(TEST_EXEC)

clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)
