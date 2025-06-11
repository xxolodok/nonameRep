#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

struct Node {
  int data;
  struct Node *next_element;
};

int add_first_element(struct Node **head, int new_data);
int add_last_element(struct Node **head, int new_data);
int add_middle_element(struct Node **head, int new_data, int position);
int delete_element(struct Node **head, int position);
int find_element_by_position(struct Node *head, int position, int *result);
int counter_of_elements(struct Node *head);

#endif
