CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -g -I.
AR=ar
ARFLAGS=rcs
RM=rm -f

LIBNAME=libmem_manager.a
SRCS=mem_manager.c
OBJS=$(SRCS:.c=.o)
TEST_SRCS=test_mem_manager.c
TEST_EXE=test_mem_manager

.PHONY: all clean test check_fmt format

all: $(LIBNAME) $(TEST_EXE)

$(LIBNAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TEST_EXE): $(TEST_SRCS) $(LIBNAME)
	$(CC) $(CFLAGS) -o $@ $^ -I. -L. -lmem_manager

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBNAME) $(TEST_EXE)

test: $(TEST_EXE)
	./$(TEST_EXE) | tee test.log

check_fmt:
	@echo "Проверка форматирования..."
	@clang-format --dry-run --Werror *.c *.h

format:
	@echo "Применение clang-format..."
	@clang-format -i *.c *.h
	