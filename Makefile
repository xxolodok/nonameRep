CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = *_test
SRCS = quadratic.c test_quadratic.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

RM = rm -rf

clean:
	@echo "Очистка репозитория от *.o, *.a и *_test..."
	@find . -type f \( -name "*.o" -o -name "*.a" -o -name "*_test" \) -exec $(RM) {} +
	@echo "Очистка завершена."

.PHONY: clean

check_fmt:
	@if find . -type f -regex ".*\.[ch]" | xargs clang-format -style=LLVM --dry-run --Werror; then \
		echo "Formatting is correct"; \
	else \
		echo "Formatting errors found"; \
		exit 1; \
	fi

fmt:
	find . -type f -regex ".*\.[ch]" | xargs clang-format -style=LLVM -i

TEST_TARGETS = $(wildcard *_test)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m 

TEST_TARGETS = $(shell find . -type f -name "*_test")

.PHONY: test 

test:
	@if [ -z "$(TEST_TARGETS)" ]; then \
		echo "${RED}Тесты не найдены.${NC}"; \
		exit 1; \
	fi
	@echo "${GREEN}Запуск тестов...${NC}"
	@for test in $(TEST_TARGETS); do \
		echo "${GREEN}Запуск $$test...${NC}"; \
		./$$test || exit 1; \
	done
	@echo "${GREEN}Все тесты пройдены.${NC}"

.PHONY: all clean check_fmt fmt test