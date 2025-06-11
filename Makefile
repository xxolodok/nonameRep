CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -g  
TARGETS = $(wildcard *_test)

RM = rm -rf
FIND = find . -type f
CLANG_FORMAT = clang-format -style=LLVM
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all \
                   --track-origins=yes --error-exitcode=1

SUBDIR_MAKEFILES = $(shell find . -mindepth 2 -type f -name "Makefile")

all: build_subdirs $(TARGETS)

build_subdirs:
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		$(MAKE) -C $$dir all || exit 1; \
	done

clean:
	@$(FIND) \( -name "*.o" -o -name "*.a" -o -name "*_test" \) -exec $(RM) {} +
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		$(MAKE) -C $$dir clean || exit 1; \
	done

check_fmt:
	@$(FIND) -name "*.[ch]" | xargs $(CLANG_FORMAT) --dry-run --Werror >/dev/null

fmt:
	@$(FIND) -name "*.[ch]" | xargs $(CLANG_FORMAT) -i >/dev/null

test_subdirs:
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		if grep -q '^test:' $$mkfile; then \
			$(MAKE) -C $$dir test || exit 1; \
		fi \
	done

test: build_subdirs test_subdirs
	@if [ -n "$(TARGETS)" ]; then \
		for test in $(TARGETS); do \
			./$$test || exit 1; \
		done; \
	fi

valgrind_subdirs:
	@for mkfile in $(SUBDIR_MAKEFILES); do \
		dir=$$(dirname $$mkfile); \
		if grep -q '^valgrind:' $$mkfile; then \
			$(MAKE) -C $$dir valgrind || exit 1; \
		fi \
	done

valgrind: build_subdirs valgrind_subdirs
	@if [ -n "$(TARGETS)" ]; then \
		for test in $(TARGETS); do \
			$(VALGRIND) ./$$test || exit 1; \
		done; \
	fi

.PHONY: all build_subdirs clean check_fmt fmt test test_subdirs valgrind valgrind_subdirs