#include "linearAlloc.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

LinearAllocator *linear_allocator_init(size_t size) {
  LinearAllocator *allocator = malloc(sizeof(LinearAllocator));
  if (!allocator)
    return NULL;

  allocator->buffer = malloc(size);
  if (!allocator->buffer) {
    free(allocator);
    return NULL;
  }

  allocator->buffer_size = size;
  allocator->offset = 0;
  return allocator;
}

void *linear_alloc(LinearAllocator *allocator, size_t size) {
  if (!allocator || allocator->offset + size > allocator->buffer_size)
    return NULL;

  void *ptr = allocator->buffer + allocator->offset;
  allocator->offset += size;

  return ptr;
}

void linear_reset(LinearAllocator *allocator) {
  if (allocator)
    allocator->offset = 0;
}

void linear_allocator_deinit(LinearAllocator *allocator) {
  if (allocator) {
    free(allocator->buffer);
    free(allocator);
  }
}
void linear_allocator_free(LinearAllocator *allocator) {
  if (allocator) {
    free(allocator->buffer);
    free(allocator);
  }
}