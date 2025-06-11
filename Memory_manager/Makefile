CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -g -I./Mem_manager
AR=ar
ARFLAGS=rcs
RM=rm -f

LIBNAME=libmem_manager.a
SRCS=Mem_manager/mem_manager.c
OBJS=$(SRCS:.c=.o)

TEST_SRCS=Mem_manager/test_mem_manager.c
TEST_EXE=test_mem_manager

.PHONY: all clean test

all: $(LIBNAME) $(TEST_EXE)

$(LIBNAME): $(OBJS)
    $(AR) $(ARFLAGS) $@ $^

$(TEST_EXE): $(TEST_SRCS) $(LIBNAME)
    $(CC) $(CFLAGS) -o $@ $^ -I./Mem_manager -L. -lmem_manager

Mem_manager/%.o: Mem_manager/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(RM) $(OBJS) $(LIBNAME) $(TEST_EXE)

test: $(TEST_EXE)
    ./$(TEST_EXE) | tee test.log