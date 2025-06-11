#include "IAllocator.h"
#include <stdio.h>
#include <stdlib.h>

void* DefaultAllocator_Allocate(size_t size) {
    return malloc(size);
}

void DefaultAllocator_Free(void* ptr) {
    free(ptr);
}

IAllocator* DefaultAllocator_Create() {
    IAllocator* allocator = (IAllocator*)malloc(sizeof(IAllocator));
    if (allocator == NULL) {
        fprintf(stderr, "Memory allocation failed for IAllocator\n");
        return NULL;
    }

    allocator->Allocate = DefaultAllocator_Allocate;
    allocator->Free = DefaultAllocator_Free;

    return allocator;
}