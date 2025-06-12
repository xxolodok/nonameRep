#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "IAllocator.h"
#include <stddef.h>

typedef struct ArrayList {
  IAllocator *allocator;
  void **items;
  size_t size;
  size_t capacity;
  size_t itemSize;
} ArrayList;

void arraylist_init(ArrayList *list, IAllocator *allocator,
                    size_t initialCapacity);
void arraylist_add(ArrayList *list, void *data, size_t index);
void *arraylist_get(const ArrayList *list, size_t index);
void arraylist_del(ArrayList *list, size_t index);
void arraylist_free(ArrayList *list);

#endif
