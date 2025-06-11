#include "linked_list.h"
#include <assert.h>

int main() {
  struct Node *head = NULL;
  int result;

  assert(counter_of_elements(head) == 0);
  assert(find_element_by_position(head, 0, &result) == -1);

  assert(add_first_element(&head, 10) == 0);
  assert(counter_of_elements(head) == 1);
  assert(find_element_by_position(head, 0, &result) == 0 && result == 10);

  assert(add_last_element(&head, 20) == 0);
  assert(counter_of_elements(head) == 2);
  assert(find_element_by_position(head, 1, &result) == 0 && result == 20);

  assert(add_middle_element(&head, 15, 1) == 0);
  assert(counter_of_elements(head) == 3);
  assert(find_element_by_position(head, 1, &result) == 0 && result == 15);

  assert(delete_element(&head, 1) == 0);
  assert(counter_of_elements(head) == 2);
  assert(find_element_by_position(head, 1, &result) == 0 && result == 20);

  return 0;
}
