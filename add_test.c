#include <stdio.h>
#include "add.h"

int main() {
    struct Stack stack;
    stack_initialization(&stack);
    
    is_empty(&stack);
    
    push(&stack, 5);
    push(&stack, 10);
    
    is_empty(&stack);
    
    printf("Удалён элемент: %d\n", pop(&stack));
    is_empty(&stack);
    
    printf("Удалён элемент: %d\n", pop(&stack));
    is_empty(&stack);
    
    return 0;
}
