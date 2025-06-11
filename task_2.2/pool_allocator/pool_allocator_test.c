#include "pool_allocator.h"
#include <assert.h>

int main() {
    PoolAllocator allocator;
    size_t block_size = 16;
    size_t num_blocks = 5;

    int init_result = pool_init(&allocator, block_size, num_blocks);
    assert(init_result == 0);

    void* block1 = pool_alloc(&allocator);
    void* block2 = pool_alloc(&allocator);
    assert(block1 != NULL);
    assert(block2 != NULL);
    assert(block1 != block2);

    int free_result1 = pool_free(&allocator, block1);
    int free_result2 = pool_free(&allocator, block2);
    assert(free_result1 == 0);
    assert(free_result2 == 0);

    void* block1_reused = pool_alloc(&allocator);
    void* block2_reused = pool_alloc(&allocator);
    assert(block1_reused != NULL);
    assert(block2_reused != NULL);

    pool_destroy(&allocator);

    return 0;
}
