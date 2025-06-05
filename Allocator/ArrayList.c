#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>

void arraylist_init(ArrayList* list, IAllocator* allocator, size_t initialCapacity) {
    if (!list || !allocator) {
        fprintf(stderr, "Error: Invalid arguments\n");
        return;
    }

    list->allocator = allocator;
    list->size = 0;
    list->capacity = initialCapacity > 0 ? initialCapacity : 1;
    list->items = (void**)list->allocator->Allocate(list->capacity * sizeof(void*));
    
    if (!list->items) {
        fprintf(stderr, "Memory allocation failed\n");
        list->capacity = 0;
    }
}

void arraylist_add(ArrayList* list, void* data, size_t index) {
    if (!list || !data || index > list->size) {
        fprintf(stderr, "Error: Invalid arguments\n");
        return;
    }

    if (list->size >= list->capacity) {
        size_t newCapacity = list->capacity * 2;
        void** newItems = list->allocator->Allocate(newCapacity * sizeof(void*));
        
        if (!newItems) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }

        for (size_t i = 0; i < list->size; ++i) {
            newItems[i] = list->items[i];
        }

        list->allocator->Free(list->items);
        list->items = newItems;
        list->capacity = newCapacity;
    }

    if (index < list->size) {
        for (size_t i = list->size; i > index; --i) {
            list->items[i] = list->items[i-1];
        }
    }
    list->items[index] = data;
    list->size++;
}

void* arraylist_get(const ArrayList* list, size_t index) {
    if (!list || index >= list->size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        return NULL;
    }
    return list->items[index];
}

void arraylist_del(ArrayList* list, size_t index) {
    if (!list || index >= list->size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        return;
    }

    for (size_t i = index; i < list->size - 1; ++i) {
        list->items[i] = list->items[i+1];
    }
    list->size--;
}

void arraylist_free(ArrayList* list) {
    if (list) {
        if (list->items) {
            list->allocator->Free(list->items);
        }
        list->items = NULL;
        list->size = 0;
        list->capacity = 0;
    }
}