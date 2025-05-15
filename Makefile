CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = *_test
SRCS = quadratic.c test_quadratic.c
OBJS = $(SRCS:.c=.o)

# Находим все поддиректории с Makefile (кроме корневой)
SUBDIRS := $(shell find . -mindepth 2 -name Makefile -exec dirname {} \; | sort | uniq)

.PHONY: all clean check_fmt fmt test subdirs $(SUBDIRS)

all: test subdirs

# Правило для рекурсивного вызова Makefile в поддиректориях
subdirs: $(SUBDIRS)

$(SUBDIRS):
	@echo "\n${GREEN}▶ Запуск Makefile в $@${NC}"
	@$(MAKE) -C $@

clean:
	@echo "Очистка репозитория от *.o, *.a и *_test..."
	@find . -type f \( -name "*.o" -o -name "*.a" -o -name "*_test" \) -exec $(RM) {} +
	@for dir in $(SUBDIRS); do \
		echo "${GREEN}▶ Очистка $$dir${NC}"; \
		$(MAKE) -C $$dir clean; \
	done
	@echo "Очистка завершена."

check_fmt:
	@if find . -type f -regex ".*\.[ch]" | xargs clang-format -style=LLVM --dry-run --Werror; then \
		echo "Formatting is correct"; \
	else \
		echo "Formatting errors found"; \
		exit 1; \
	fi
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir check_fmt || exit 1; \
	done

fmt:
	find . -type f -regex ".*\.[ch]" | xargs clang-format -style=LLVM -i
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fmt; \
	done

TEST_TARGETS = $(wildcard *_test)
TEST_TARGETS += $(shell find . -mindepth 2 -type f -name "*_test")

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
	@for dir in $(SUBDIRS); do \
		echo "${GREEN}▶ Тесты в $$dir${NC}"; \
		$(MAKE) -C $$dir test || exit 1; \
	done
	@echo "${GREEN}Все тесты пройдены.${NC}"

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
