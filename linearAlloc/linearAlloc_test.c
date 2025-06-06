#include "linearAlloc.h"
#include <assert.h>
#include <stdio.h>

int main() {
  size_t alloc_size = 1024;
  LinearAllocator *allocator = linear_allocator_init(alloc_size);
  assert(allocator->buffer_size == alloc_size);

  size_t block1 = 256;
  void *ptr1 = linear_alloc(allocator, block1);
  assert(ptr1 != NULL);
  assert(allocator->offset == block1);

  size_t block2 = 512;
  void *ptr2 = linear_alloc(allocator, block2);
  assert(ptr2 != NULL);
  assert(allocator->offset == block1 + block2);

  size_t block3 = 512;
  void *ptr3 = linear_alloc(allocator, block3);
  assert(ptr3 == NULL);

  linear_reset(allocator);
  assert(allocator->offset == 0);

  void *ptr4 = linear_alloc(allocator, alloc_size);
  assert(ptr4 != NULL);
  assert(allocator->offset == alloc_size);
  linear_allocator_deinit(allocator);
  return 0;
}

