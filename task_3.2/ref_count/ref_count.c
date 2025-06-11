#include "ref_count.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

static PoolAllocator allocator;
static int initialized = 0;

int ref_count_init(size_t pool_blocks) {
  assert(pool_blocks > 0);

  if (initialized) {
    return -1;
  }

  if (pool_init(&allocator, sizeof(ref_count_t), pool_blocks) != 0) {
    return -1;
  }

  initialized = 1;
  return 0;
}

void ref_count_destroy(void) {
  if (!initialized) {
    return;
  }

  pool_destroy(&allocator);
  initialized = 0;
}

ref_count_t *ref_count_create(void *object) {
  assert(initialized);
  if (object == NULL) {
    return NULL;
  }

  ref_count_t *ref = pool_alloc(&allocator);
  if (ref == NULL) {
    return NULL;
  }

  ref->count = 1;
  ref->object = object;

  return ref;
}

int ref_count_retain(ref_count_t *ref) {
  if (!initialized || ref == NULL) {
    return -1;
  }

  if (ref->count == SIZE_MAX) {
    return -1;
  }

  ref->count++;
  return 0;
}

int ref_count_release(ref_count_t *ref) {
  if (!initialized || ref == NULL) {
    return -1;
  }

  if (ref->count == 0) {
    return -1;
  }

  ref->count--;

  if (ref->count == 0) {
    free(ref->object);
    if (pool_free(&allocator, ref) != 0) {
      return -1;
    }
  }

  return 0;
}


