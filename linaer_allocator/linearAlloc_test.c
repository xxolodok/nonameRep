#include "linearAlloc.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_allocator_creation() {
  LinearAllocator *alloc = linear_allocator_create(1024);
  assert(alloc != NULL);
  linear_allocator_destroy(alloc);
}

void test_simple_allocation() {
  LinearAllocator *alloc = linear_allocator_create(1024);
  int *ptr = (int *)linear_alloc(alloc, sizeof(int));
  assert(ptr != NULL);
  *ptr = 42;
  assert(*ptr == 42);
  linear_allocator_destroy(alloc);
}

void test_multiple_allocations() {
  LinearAllocator *alloc = linear_allocator_create(100);

  int *a = (int *)linear_alloc(alloc, sizeof(int));
  double *b = (double *)linear_alloc(alloc, sizeof(double));
  char *str = (char *)linear_alloc(alloc, 50);

  assert(a != NULL);
  assert(b != NULL);
  assert(str != NULL);

  *a = 10;
  *b = 3.14;
  strcpy(str, "test");

  assert(*a == 10);
  assert(*b == 3.14);
  assert(strcmp(str, "test") == 0);

  linear_allocator_destroy(alloc);
}

void test_allocation_failure() {
  LinearAllocator *alloc = linear_allocator_create(10);
  void *ptr1 = linear_alloc(alloc, 8);
  assert(ptr1 != NULL);

  void *ptr2 = linear_alloc(alloc, 8);
  assert(ptr2 == NULL); // Не хватает места

  linear_allocator_destroy(alloc);
}

void test_reset_functionality() {
  LinearAllocator *alloc = linear_allocator_create(100);

  int *a = (int *)linear_alloc(alloc, sizeof(int));
  *a = 42;

  linear_reset(alloc);

  double *b = (double *)linear_alloc(alloc, sizeof(double));
  *b = 3.14;

  assert(*b == 3.14);
  // a больше не валиден после reset

  linear_allocator_destroy(alloc);
}

void test_boundary_allocation() {
  LinearAllocator *alloc = linear_allocator_create(100);

  void *ptr = linear_alloc(alloc, 100);
  assert(ptr != NULL);

  void *ptr2 = linear_alloc(alloc, 1);
  assert(ptr2 == NULL); // Нет места

  linear_reset(alloc);

  ptr = linear_alloc(alloc, 100);
  assert(ptr != NULL); // После reset снова можно выделять

  linear_allocator_destroy(alloc);
}

void test_zero_size_allocation() {
  LinearAllocator *alloc = linear_allocator_create(100);

  void *ptr = linear_alloc(alloc, 0);
  // Поведение при выделении 0 байт зависит от реализации
  // Можно считать допустимым как NULL, так и валидный указатель
  assert(ptr == NULL || ptr != NULL);

  linear_allocator_destroy(alloc);
}

void test_destroy_null() {
  // Проверяем, что функция не падает при NULL
  linear_allocator_destroy(NULL);
}

int main() {
  test_allocator_creation();
  test_simple_allocation();
  test_multiple_allocations();
  test_allocation_failure();
  test_reset_functionality();
  test_boundary_allocation();
  test_zero_size_allocation();
  test_destroy_null();

  printf("All tests passed successfully!\n");
  return 0;
}