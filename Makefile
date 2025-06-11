CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGETS = $(wildcard *_test)

RM = rm -rf
FIND = find . -type f
CLANG_FORMAT = clang-format -style=LLVM

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
		targets=$$(grep -E '^[a-zA-Z0-9_-]+_test:' $$mkfile | cut -d: -f1); \
		for target in $$targets; do \
			echo "Running $$target in $$dir..."; \
			$(MAKE) -C $$dir $$target || exit 1; \
		done \
	done
test: build_subdirs test_subdirs
	@if [ -n "$(TARGETS)" ]; then \
		for test in $(TARGETS); do \
			./$$test || exit 1; \
		done; \
	fi

.PHONY: all build_subdirs clean check_fmt fmt test test_subdirs
