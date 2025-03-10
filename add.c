#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Stack {
    int array[MAX];
    int last_element;
};

// Инициализация стека
void stack_initialization(struct Stack* stack) {
    stack->last_element = -1;
}

//Проверка стека на наличие в нем элемента
void is_empty(struct Stack* stack) {
    if (stack->last_element == -1) {
        printf("Стек пуст\n");
    } else {
        printf("Стек не пуст\n");
    }
}

//Операция добавления нового элемента
void push(struct Stack* stack, int value) {
    if (stack->last_element < MAX - 1) {
        stack->last_element++;
        stack->array[stack->last_element] = value;
    } else {
        printf("Стек полон\n");
    }
}

//Операция удаления нового элемента
int pop(struct Stack* stack) {
    if (stack->last_element >= 0) {                  
        int value = stack->array[stack->last_element];
        stack->last_element--;                         
        return value;                        
    } else {                                
        printf("Стек пуст\n");               
        return -1;                           
    }
}
