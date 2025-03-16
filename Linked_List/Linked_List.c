#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next_element;
};




//Добавление в начало списка
void add_first_element(struct Node** head, int new_data) {
    struct Node* new_first_element = (struct Node*)malloc(sizeof(struct Node));
    new_first_element->data = new_data;
    new_first_element->next_element = *head;
    *head = new_first_element;
}





//Добавление в конец списка
void add_last_element(struct Node** head, int new_data) {
    struct Node* new_last_element = (struct Node*)malloc(sizeof(struct Node));
    new_last_element->data = new_data;
    new_last_element->next_element = NULL;

    if (*head == NULL) {
        *head = new_last_element;
        return;
    }

    struct Node* temp = *head;
    while (temp->next_element != NULL) {
        temp = temp->next_element;
    }
    
    temp->next_element = new_last_element;
}





//Добавление по порядковому номеру
void add_middle_element(struct Node** head, int new_data, int position) {
    if (position == 0) {  
        add_first_element(head, new_data);  
        return;
    }

    struct Node* new_middle_element = (struct Node*)malloc(sizeof(struct Node));
    new_middle_element->data = new_data;

    struct Node* temp = *head;

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next_element;
    }

    if (temp == NULL) {
        printf("Порядковый номер выходит за пределы списка\n");
        free(new_middle_element);
        return;
    }

    new_middle_element->next_element = temp->next_element;
    temp->next_element = new_middle_element;
}




//Удаление элемента
void delete_element(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Список пуст\n");
        return;
    }

    struct Node* temp = *head;

    if (position < 0) {
        printf("Некорректная позиция\n");
        return;
    }

    if (position == 0) {
        *head = temp->next_element;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next_element;
    }   

    if (temp == NULL || temp->next_element == NULL) {
        printf("Элемент не найден\n");
        return;
    }

    struct Node* next = temp->next_element->next_element;

    free(temp->next_element); 

    temp->next_element = next;
}   





// Поиск элемента по порядковому номеру
int find_element_by_position(struct Node* head, int position) {
    struct Node* temp = head;

    if (position < 0) {
        printf("Некорректная позиция\n");
        return -1;
    }
    
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next_element;
    }

    if (temp != NULL) {
        return temp->data;
    }

    printf("Элемент не найден\n");
    return -1;
}






// Подсчёт количества элементов
int counter_of_elements(struct Node* head) {
    int counter = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        counter++;
        temp = temp->next_element;
    }

    return counter;
}
