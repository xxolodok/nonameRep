#ifndef IALLOCATOR_H
#define IALLOCATOR_H

#include <stdlib.h>

typedef struct IAllocator {
  void *(*Allocate)(size_t size);
  void (*Free)(void *ptr);
} IAllocator;

typedef struct DefaultAllocator {
} DefaultAllocator;

void *DefaultAllocator_Allocate(size_t size);
void DefaultAllocator_Free(void *ptr);

IAllocator *DefaultAllocator_Create();

#endif
