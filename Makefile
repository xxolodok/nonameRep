# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGETS = $(wildcard *_test)

# Утилиты
RM = rm -rf
FIND = find . -type f
CLANG_FORMAT = clang-format -style=LLVM

# Цвета для вывода
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

# Поиск всех Makefile в поддиректориях (исключая текущую)
SUBDIR_MAKEFILES = $(shell find . -mindepth 2 -type f -name "Makefile")

# Основная цель (сначала сборка в поддиректориях, затем текущая)
all: build_subdirs $(TARGETS)

build_subdirs:
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		echo "${GREEN}▶ Сборка в $$dir${NC}"; \
		$(MAKE) -C $$dir all || exit 1; \
	done

# Очистка проекта (рекурсивная)
clean:
	@echo "${GREEN}Очистка рабочей директории...${NC}"
	@$(FIND) \( -name "*.o" -o -name "*.a" -o -name "*_test" \) -exec $(RM) {} +
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		echo "${GREEN}▶ Очистка $$dir${NC}"; \
		$(MAKE) -C $$dir clean || exit 1; \
	done
	@echo "${GREEN}Очистка завершена.${NC}"

# Вывод списка всех Makefile
list_makefiles:
	@echo "${GREEN}Найдены Makefile в поддиректориях:${NC}"
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		echo "$$mkfile"; \
	done

check_fmt:
	@echo "${GREEN}Проверка форматирования...${NC}"
	@if $(FIND) -name "*.[ch]" | xargs $(CLANG_FORMAT) --dry-run --Werror; then \
		echo "${GREEN}Форматирование корректно.${NC}"; \
	else \
		echo "${RED}Ошибки форматирования!${NC}"; \
		exit 1; \
	fi

fmt:
	@echo "${GREEN}Применение форматирования...${NC}"
	@$(FIND) -name "*.[ch]" | xargs $(CLANG_FORMAT) -i
	@echo "${GREEN}Готово.${NC}"

# Запуск тестов в поддиректориях
test_subdirs:
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		echo "${GREEN}▶ Тесты в $$dir${NC}"; \
		$(MAKE) -C $$dir test || exit 1; \
	done

# Основная цель тестирования (сначала сборка, затем тесты везде)
test: build_subdirs test_subdirs
	@if [ -z "$(TARGETS)" ]; then \
		echo "${RED}Тесты не найдены в текущей директории.${NC}"; \
	else \
		echo "${GREEN}Запуск тестов в текущей директории...${NC}"; \
		for test in $(TARGETS); do \
			echo "${GREEN}▶ $$test${NC}"; \
			./$$test || exit 1; \
		done; \
		echo "${GREEN}✅ Все тесты в текущей директории пройдены.${NC}"; \
	fi
	@echo "${GREEN}✅ Все тесты во всех директориях пройдены.${NC}"

.PHONY: all build_subdirs clean list_makefiles check_fmt fmt test test_subdirs
