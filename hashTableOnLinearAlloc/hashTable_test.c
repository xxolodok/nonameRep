#include "hashTable.h"
#include "linearAlloc.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void setup(LinearAllocator **allocator, HashTable *table, size_t capacity) {
  *allocator = linear_allocator_init(1024 * 64);
  hashtable_init(table, capacity, *allocator);
}

void test_insert_and_get(LinearAllocator *allocator, HashTable *table) {
  int val1 = 100;
  int val2 = 200;

  hashtable_insert(table, "key1", &val1);
  hashtable_insert(table, "key2", &val2);

  assert(hashtable_get(table, "key1") == &val1);
  assert(hashtable_get(table, "key2") == &val2);
}

void test_update_value(LinearAllocator *allocator, HashTable *table) {
  int val1 = 100;
  int val2 = 200;

  hashtable_insert(table, "key1", &val1);
  hashtable_insert(table, "key1", &val2);

  assert(hashtable_get(table, "key1") == &val2);
}

void test_delete_key(LinearAllocator *allocator, HashTable *table) {
  int val1 = 100;

  hashtable_insert(table, "key1", &val1);
  hashtable_del(table, "key1");

  assert(hashtable_get(table, "key1") == NULL);
}

void test_get_nonexistent_key(LinearAllocator *allocator, HashTable *table) {
  assert(hashtable_get(table, "nonexistent") == NULL);
}

void test_collision_handling(LinearAllocator *allocator, HashTable *table) {
  int val1 = 1;
  int val2 = 2;

  hashtable_insert(table, "keyA", &val1);
  hashtable_insert(table, "keyB", &val2);

  assert(hashtable_get(table, "keyA") == &val1);
  assert(hashtable_get(table, "keyB") == &val2);
}

int main() {
  LinearAllocator *allocator;
  HashTable table;

  setup(&allocator, &table, 8);

  test_insert_and_get(allocator, &table);
  test_update_value(allocator, &table);
  test_delete_key(allocator, &table);
  test_get_nonexistent_key(allocator, &table);
  test_collision_handling(allocator, &table);

  hashtable_free(&table);
  linear_allocator_free(allocator);

  return 0;
}
