#include "linked_list.h"
#include <stdlib.h>

int add_first_element(struct Node **head, int new_data) {
  if (head == NULL) {
    return -1;
  }

  struct Node *new_first_element = malloc(sizeof(struct Node));
  if (new_first_element == NULL) {
    return -1;
  }

  new_first_element->data = new_data;
  new_first_element->next_element = *head;
  *head = new_first_element;

  return 0;
}

int add_last_element(struct Node **head, int new_data) {
  if (head == NULL) {
    return -1;
  }

  struct Node *new_last_element = malloc(sizeof(struct Node));
  if (new_last_element == NULL) {
    return -1;
  }

  new_last_element->data = new_data;
  new_last_element->next_element = NULL;

  if (*head == NULL) {
    *head = new_last_element;
    return 0;
  }

  struct Node *temp = *head;
  while (temp->next_element != NULL) {
    temp = temp->next_element;
  }

  temp->next_element = new_last_element;
  return 0;
}

int add_middle_element(struct Node **head, int new_data, int position) {
  if (head == NULL || position < 0) {
    return -1;
  }

  if (position == 0) {
    return add_first_element(head, new_data);
  }

  struct Node *new_middle_element = malloc(sizeof(struct Node));
  if (new_middle_element == NULL) {
    return -1;
  }

  new_middle_element->data = new_data;

  struct Node *temp = *head;
  for (int i = 0; temp != NULL && i < position - 1; i++) {
    temp = temp->next_element;
  }

  if (temp == NULL) {
    free(new_middle_element);
    return -1;
  }

  new_middle_element->next_element = temp->next_element;
  temp->next_element = new_middle_element;
  return 0;
}

int delete_element(struct Node **head, int position) {
  if (head == NULL || *head == NULL || position < 0) {
    return -1;
  }

  struct Node *temp = *head;

  if (position == 0) {
    *head = temp->next_element;
    free(temp);
    return 0;
  }

  for (int i = 0; temp != NULL && i < position - 1; i++) {
    temp = temp->next_element;
  }

  if (temp == NULL || temp->next_element == NULL) {
    return -1;
  }

  struct Node *next = temp->next_element->next_element;
  free(temp->next_element);
  temp->next_element = next;

  return 0;
}

int find_element_by_position(struct Node *head, int position, int *result) {
  if (position < 0 || result == NULL) {
    return -1;
  }

  struct Node *temp = head;
  for (int i = 0; temp != NULL && i < position; i++) {
    temp = temp->next_element;
  }

  if (temp == NULL) {
    return -1;
  }

  *result = temp->data;
  return 0;
}

int counter_of_elements(struct Node *head) {
  int counter = 0;
  struct Node *temp = head;

  while (temp != NULL) {
    counter++;
    temp = temp->next_element;
  }

  return counter;
}
