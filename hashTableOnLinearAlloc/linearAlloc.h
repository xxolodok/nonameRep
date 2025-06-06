#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H
#include <stddef.h>
#include <stdint.h>

typedef struct {
  uint8_t *buffer;
  size_t buffer_size;
  size_t offset;
} LinearAllocator;

LinearAllocator *linear_allocator_init(size_t size);
void *linear_alloc(LinearAllocator *allocator, size_t size);
void linear_reset(LinearAllocator *allocator);
void linear_allocator_deinit(LinearAllocator *allocator);
void linear_allocator_free(LinearAllocator *allocator);

#endif
