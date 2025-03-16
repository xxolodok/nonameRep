#include <stdio.h>
#include <assert.h>
#include "Linked_List.h"

int main() {
    struct Node* head = NULL;

    add_first_element(&head, 10);
    add_last_element(&head, 20);
    add_middle_element(&head, 15, 1);

    assert(find_element_by_position(head, 0) == 10);
    assert(find_element_by_position(head, 1) == 15);
    assert(find_element_by_position(head, 2) == 20);

    delete_element(&head, 1);
    assert(find_element_by_position(head, 1) == 20);
    
    assert(counter_of_elements(head) == 2);

    printf("Все тесты пройдены успешно!\n");
    return 0;
}
