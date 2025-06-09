#include "array-based_stack.h"
#include <assert.h>
#include <stdlib.h>

void stack_initialization(struct Stack *stack, int max_size) {
  assert(max_size > 0);
  stack->array = malloc(max_size * sizeof(int));
  assert(stack->array != NULL);
  stack->capacity = max_size;
  stack->last_element = -1;
}

int is_empty(struct Stack *stack) {
  return (stack->last_element == -1);
}

int push(struct Stack *stack, int value) {
  if (stack->last_element >= stack->capacity - 1) {
    return -1;
  }
  stack->last_element++;
  stack->array[stack->last_element] = value;
  return 0;
}

int pop(struct Stack *stack, int *out_value) {
  if (is_empty(stack)) {
    return -1;
  }
  *out_value = stack->array[stack->last_element];
  stack->last_element--;
  return 0;
}

void stack_free(struct Stack *stack) {
  free(stack->array);
  stack->array = NULL;
  stack->capacity = 0;
  stack->last_element = -1;
}
