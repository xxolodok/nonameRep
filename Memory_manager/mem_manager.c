#include "mem_manager.h"

void* allocate_memory(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Ошибка: попытка выделить 0 байт.\n");
        return NULL;
    }
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Ошибка: не удалось выделить память.\n");
    }
    return ptr;
}

void free_memory(void** ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
    } else {
        fprintf(stderr, "Предупреждение: попытка освободить NULL-указатель.\n");
    }
}