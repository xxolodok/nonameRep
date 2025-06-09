#include "array-based_stack.h"
#include <assert.h>
#include <stdio.h>

int main() {
  struct Stack stack;
  stack_initialization(&stack, 3);

  assert(is_empty(&stack) == 1);

  assert(push(&stack, 5) == 0);
  assert(push(&stack, 10) == 0);

  assert(is_empty(&stack) == 0);

  assert(pop(&stack) == 10);
  assert(pop(&stack) == 5);

  assert(is_empty(&stack) == 1);

  stack_free(&stack);
  return 0;
}
