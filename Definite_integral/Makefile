CC=gcc
CFLAGS=-Wall -Werror
TEST_FLAGS=-lcheck

SRC=definite_integral.c
OBJ=$(SRC:.c=.o)
EXEC=definite_integral

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test: $(EXEC)
	$(CC) $(OBJ) test_definite_integral.c -o test_definite_integral $(TEST_FLAGS)
	./test_definite_integral

clean:
	rm -f *.o $(EXEC) test_definite_integral
