# Общий Makefile для рекурсивной сборки проекта
CC = gcc
CFLAGS = -g
LDFLAGS = -lm

# Находим все поддиректории с Makefile (кроме корневой)
SUBDIRS := $(shell find . -mindepth 2 -name Makefile -exec dirname {} \; | sort | uniq)

.PHONY: all clean test $(SUBDIRS)

# Основные цели
all: build

build: $(SUBDIRS)
	@echo "${GREEN}▶ Сборка всех подпроектов завершена${NC}"

test: $(SUBDIRS)
	@echo "${GREEN}▶ Запуск всех тестов${NC}"
	@for dir in $(SUBDIRS); do \
		echo "${BLUE}▶ Тестирование $$dir${NC}"; \
		$(MAKE) -C $$dir test || exit 1; \
	done
	@echo "${GREEN}✓ Все тесты пройдены успешно${NC}"

# Рекурсивный вызов Makefile в поддиректориях
$(SUBDIRS):
	@echo "${CYAN}▶ Сборка в $@${NC}"
	@$(MAKE) -C $@ $(MAKECMDGOALS)

clean:
	@echo "${YELLOW}▶ Очистка проекта${NC}"
	@for dir in $(SUBDIRS); do \
		echo "${YELLOW}▶ Очистка $$dir${NC}"; \
		$(MAKE) -C $$dir clean; \
	done
	@rm -f *.o *.a *_test
	@echo "${GREEN}✓ Очистка завершена${NC}"

# Цвета для вывода
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[0;36m
NC = \033[0m
