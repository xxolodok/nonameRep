#include <stdio.h>
#include "mem_manager.h"

int test_allocate_memory() {
    void* ptr = allocate_memory(128);
    if (!ptr) {
        return 0;
    }
    free_memory(&ptr);
    return ptr == NULL;
}

int test_free_memory() {
    void* ptr = allocate_memory(256);
    free_memory(&ptr);
    return ptr == NULL;
}

int test_double_free() {
    void* ptr = allocate_memory(64);
    free_memory(&ptr);
    free_memory(&ptr);
    return ptr == NULL;
}

int test_allocate_zero_size() {
    void* ptr = allocate_memory(0);
    return ptr == NULL;
}

int main() {
    printf("Запуск тестов...\n");

    if (test_allocate_memory()) {
        printf("Тест allocate_memory пройден\n");
    } else {
        printf("Тест allocate_memory не пройден\n");
    }

    if (test_free_memory()) {
        printf("Тест free_memory пройден\n");
    } else {
        printf("Тест free_memory не пройден\n");
    }

    if (test_double_free()) {
        printf("Тест double_free пройден\n");
    } else {
        printf("Тест double_free не пройден\n");
    }

    if (test_allocate_zero_size()) {
        printf("Тест allocate_zero_size пройден\n");
    } else {
        printf("Тест allocate_zero_size не пройден\n");
    }

    return 0;
}