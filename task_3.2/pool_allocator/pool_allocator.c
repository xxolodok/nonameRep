#include "pool_allocator.h"
#include <stdlib.h>

int pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks) {
  assert(allocator != NULL);
  assert(block_size > 0);
  assert(num_blocks > 0);

  if (block_size < sizeof(void *)) {
    block_size = sizeof(void *);
  }

  allocator->block_size = block_size;
  allocator->num_blocks = num_blocks;
  allocator->memory_pool = malloc(block_size * num_blocks);

  if (!allocator->memory_pool) {
    return -1;
  }

  allocator->free_list = allocator->memory_pool;
  void **current = (void **)allocator->memory_pool;

  for (size_t i = 0; i < num_blocks - 1; i++) {
    *current = (char *)current + block_size;
    current = (void **)*current;
  }
  *current = NULL;

  return 0;
}

void *pool_alloc(PoolAllocator *allocator) {
  assert(allocator != NULL);

  if (!allocator->free_list) {
    return NULL;
  }

  void *block = allocator->free_list;
  allocator->free_list = *(void **)block;
  return block;
}

int pool_free(PoolAllocator *allocator, void *ptr) {
  assert(allocator != NULL);
  assert(ptr != NULL);

  for (void *current = allocator->free_list; current;
       current = *(void **)current) {
    if (current == ptr) {
      return -1;
    }
  }

  *(void **)ptr = allocator->free_list;
  allocator->free_list = ptr;
  return 0;
}

void pool_destroy(PoolAllocator *allocator) {
  if (!allocator)
    return;

  free(allocator->memory_pool);
  allocator->memory_pool = NULL;
  allocator->free_list = NULL;
}

