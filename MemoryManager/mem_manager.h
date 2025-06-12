#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void *allocate_memory(size_t size);
void free_memory(void **ptr);

#endif
