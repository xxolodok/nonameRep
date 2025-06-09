#ifndef ARRAY_BASED_STACK_H
#define ARRAY_BASED_STACK_H

#include <stddef.h>

struct Stack {
  int *array;
  int capacity;
  int last_element;
};

void stack_initialization(struct Stack *stack, int max_size);
int is_empty(struct Stack *stack);
int push(struct Stack *stack, int value);
int pop(struct Stack *stack);
void stack_free(struct Stack *stack);

#endif
