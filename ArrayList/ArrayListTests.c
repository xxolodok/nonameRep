#include "ArrayList.h"
#include "IAllocator.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

IAllocator* create_simple_allocator() {
    return DefaultAllocator_Create();
}

void test_add_and_get() {
    IAllocator* allocator = create_simple_allocator();
    ArrayList list;
    arraylist_init(&list, allocator, 4);

    int a = 10, b = 20;
    arraylist_add(&list, &a, 0);
    arraylist_add(&list, &b, 1);

    assert(*(int*)arraylist_get(&list, 0) == 10);
    assert(*(int*)arraylist_get(&list, 1) == 20);

    arraylist_free(&list);
    allocator->Free(allocator);
}

void test_remove_at() {
    IAllocator* allocator = create_simple_allocator();
    ArrayList list;
    arraylist_init(&list, allocator, 4);

    int a = 10, b = 20, c = 30;
    arraylist_add(&list, &a, 0);
    arraylist_add(&list, &b, 1);
    arraylist_add(&list, &c, 2);

    arraylist_del(&list, 1);
    assert(list.size == 2);
    assert(*(int*)arraylist_get(&list, 0) == 10);
    assert(*(int*)arraylist_get(&list, 1) == 30);

    arraylist_free(&list);
    allocator->Free(allocator);
}

void test_free() {
    IAllocator* allocator = create_simple_allocator();
    ArrayList list;
    arraylist_init(&list, allocator, 4);
    
    int a = 10;
    arraylist_add(&list, &a, 0);
    arraylist_free(&list);
    
    assert(list.items == NULL);
    assert(list.size == 0);
    assert(list.capacity == 0);
    
    allocator->Free(allocator);
}

void test_add_many() {
    IAllocator* allocator = create_simple_allocator();
    ArrayList list;
    arraylist_init(&list, allocator, 4);

    int* values = malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++) {
        values[i] = i;
        arraylist_add(&list, &values[i], i);
    }
    
    assert(list.size == 1000);
    for (int i = 0; i < 1000; i++) {
        assert(*(int*)arraylist_get(&list, i) == i);
    }
    
    arraylist_free(&list);
    free(values);
    allocator->Free(allocator);
}

int main() {
    printf("Running tests...\n");

    test_add_and_get();
    printf("test_add_and_get passed\n");

    test_remove_at();
    printf("test_remove_at passed\n");

    test_free();
    printf("test_free passed\n");

    test_add_many();
    printf("test_add_many passed\n");

    printf("All tests passed!\n");
    return 0;
}
