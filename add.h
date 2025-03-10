#ifndef ADD_H
#define ADD_H

#define MAX 100

struct Stack {
    int array[MAX];
    int last_element;
};

void stack_initialization(struct Stack* stack);
int is_empty(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);

#endif
