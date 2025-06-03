#include "linearAlloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Внутренняя структура аллокатора


LinearAllocator* linear_allocator_create(size_t size) {
    // Выделяем память под структуру аллокатора
    LinearAllocator* allocator = malloc(sizeof(LinearAllocator));
    if (!allocator) return NULL;
    
    // Выделяем основной буфер памяти
    allocator->buffer = malloc(size);
    if (!allocator->buffer) {
        free(allocator);
        return NULL;
    }
    
    allocator->buffer_size = size;
    allocator->offset = 0;
    return allocator;
}

void* linear_alloc(LinearAllocator* allocator, size_t size) {
    // Проверяем, есть ли достаточно места
    if (!allocator || allocator->offset + size > allocator->buffer_size) {
        return NULL;
    }
    
    // Получаем указатель на текущую позицию
    void* ptr = allocator->buffer + allocator->offset;
    
    // Увеличиваем смещение
    allocator->offset += size;
    
    return ptr;
}

void linear_reset(LinearAllocator* allocator) {
    if (allocator) {
        allocator->offset = 0;
    }
}

void linear_allocator_destroy(LinearAllocator* allocator) {
    if (allocator) {
        free(allocator->buffer);
        free(allocator);
    }
}