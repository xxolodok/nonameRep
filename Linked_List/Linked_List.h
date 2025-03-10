#ifndef LL_H
#define LL_H

struct Node {
    int data;
    struct Node* next_element;
};

void add_first_element(struct Node** head, int new_data);
void add_last_element(struct Node** head, int new_data);
void add_middle_element(struct Node** head, int new_data, int position);
void delete_element(struct Node** head, int position);
int find_element_by_position(struct Node* head, int position);
int counter_of_elements(struct Node* head);

#endif
