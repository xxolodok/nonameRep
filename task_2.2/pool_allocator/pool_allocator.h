#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stddef.h>
#include <assert.h>

typedef struct PoolAllocator {
    size_t block_size;
    size_t num_blocks;
    void* memory_pool;
    void* free_list;
} PoolAllocator;

int pool_init(PoolAllocator* allocator, size_t block_size, size_t num_blocks);
void* pool_alloc(PoolAllocator* allocator);
int pool_free(PoolAllocator* allocator, void* ptr);
void pool_destroy(PoolAllocator* allocator);

#endif
