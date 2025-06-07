#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void* allocate_memory(size_t size);
void free_memory(void** ptr);

#endif