#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arraylist_init(ArrayList *list, IAllocator *allocator,
                    size_t initialCapacity) {
  if (!list || !allocator) {
    return;
  }

  list->allocator = allocator;
  list->size = 0;
  list->capacity = initialCapacity > 0 ? initialCapacity : 1;
  list->items =
      (void **)list->allocator->Allocate(list->capacity * sizeof(void *));
}

void arraylist_add(ArrayList *list, void *data, size_t index) {
  if (!list || !data || index > list->size) {
    return;
  }

  if (list->size >= list->capacity) {
    size_t newCapacity = list->capacity * 2;
    void **newItems = list->allocator->Allocate(newCapacity * sizeof(void *));

    if (!newItems) {
      return;
    }

    memcpy(newItems, list->items, list->size * sizeof(void *));

    list->allocator->Free(list->items);
    list->items = newItems;
    list->capacity = newCapacity;
  }

  if (index < list->size) {
    memmove(&list->items[index + 1], &list->items[index],
            (list->size - index) * sizeof(void *));
  }

  list->items[index] = data;
  list->size++;
}

void *arraylist_get(const ArrayList *list, size_t index) {
  if (!list || index >= list->size) {
    return NULL;
  }
  return list->items[index];
}

void arraylist_del(ArrayList *list, size_t index) {
  if (!list || index >= list->size) {
    return;
  }

  memmove(&list->items[index], &list->items[index + 1],
          (list->size - index - 1) * sizeof(void *));
  list->size--;
}

void arraylist_free(ArrayList *list) {
  if (list) {
    if (list->items) {
      list->allocator->Free(list->items);
    }
    list->items = NULL;
    list->size = 0;
    list->capacity = 0;
  }
}
