#ifndef REF_COUNT_H
#define REF_COUNT_H

#include "pool_allocator.h"
#include <stddef.h>

typedef struct {
  size_t count;
  void *object;
} ref_count_t;

int ref_count_init(size_t pool_blocks);
void ref_count_destroy(void);

ref_count_t *ref_count_create(void *object);
int ref_count_retain(ref_count_t *ref);
int ref_count_release(ref_count_t *ref);

#endif
