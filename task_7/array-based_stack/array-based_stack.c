
#include "array-based_stack.h"
#include <assert.h>
#include <stdlib.h>

// Инициализация стека
void stack_initialization(struct Stack *stack, int max_size) {
  assert(max_size > 0);
  stack->array = malloc(max_size * sizeof(int));
  assert(stack->array != NULL);
  stack->capacity = max_size;
  stack->last_element = -1;
}

// Проверка стека на наличие в нем элемента
int is_empty(struct Stack *stack) { return (stack->last_element == -1); }

// Операция добавления нового элемента
int push(struct Stack *stack, int value) {
  if (stack->last_element >= stack->capacity - 1) {
    return -1;
  }
  stack->last_element++;
  stack->array[stack->last_element] = value;
  return 0;
}

// Операция удаления нового элемента
int pop(struct Stack *stack) {
  if (is_empty(stack)) {
    return -1; // Стек пуст
  }
  int value = stack->array[stack->last_element];
  stack->last_element--;
  return value;
}

void stack_free(struct Stack *stack) {
  free(stack->array);
  stack->array = NULL;
  stack->capacity = 0;
  stack->last_element = -1;
}

