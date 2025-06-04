#include "hashTable.h"
#include "linearAlloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

void test_hashtable_with_n_elements(size_t n) {
  printf("Test with %zu elements\n", n);

  // Инициализация линейного аллокатора через функцию, которая возвращает
  // указатель
  LinearAllocator *allocator = linear_allocator_init(n * 64);
  if (!allocator) {
    printf("Failed to initialize linear allocator\n");
    return;
  }

  HashTable table;
  hashtable_init(&table, n * 2,
                 allocator); // емкость в 2 раза больше для снижения коллизий

  char key[MAX_KEY_LEN];
  int *values = malloc(n * sizeof(int));
  if (!values) {
    printf("Failed to allocate values array\n");
    linear_allocator_free(allocator);
    return;
  }

  // Вставка элементов
  for (size_t i = 0; i < n; i++) {
    snprintf(key, sizeof(key), "key%zu", i);
    values[i] = (int)i * 10;
    hashtable_insert(&table, key, &values[i]);
  }

  // Проверка получения элементов
  for (size_t i = 0; i < n; i++) {
    snprintf(key, sizeof(key), "key%zu", i);
    int *val = (int *)hashtable_get(&table, key);
    if (!val) {
      printf("Error: key %s not found\n", key);
    } else if (*val != (int)i * 10) {
      printf("Error: key %s has wrong value %d, expected %d\n", key, *val,
             (int)i * 10);
    }
  }

  // Проверка удаления половины элементов
  for (size_t i = 0; i < n; i += 2) {
    snprintf(key, sizeof(key), "key%zu", i);
    hashtable_del(&table, key);
  }

  // Проверка после удаления
  for (size_t i = 0; i < n; i++) {
    snprintf(key, sizeof(key), "key%zu", i);
    int *val = (int *)hashtable_get(&table, key);
    if (i % 2 == 0) {
      if (val != NULL) {
        printf("Error: key %s should be deleted but found value %d\n", key,
               *val);
      }
    } else {
      if (!val || *val != (int)i * 10) {
        printf("Error: key %s missing or wrong value after deletion\n", key);
      }
    }
  }

  printf("Size after deletion: %zu, expected: %zu\n", table.size, n / 2);

  hashtable_free(&table);
  linear_allocator_free(allocator);
  free(values);

  printf("Test with %zu elements completed\n\n", n);
}

int main() {
  // Тесты с разным количеством элементов
  test_hashtable_with_n_elements(1);
  test_hashtable_with_n_elements(10);
  test_hashtable_with_n_elements(100);
  test_hashtable_with_n_elements(1000);

  return 0;
}
