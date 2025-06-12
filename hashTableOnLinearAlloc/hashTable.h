#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linearAlloc.h"
#include <stddef.h>

typedef struct HashTableItem {
  char *key;
  void *value;
  int is_occupied;
} HashTableItem;

typedef struct HashTable {
  HashTableItem *items;
  size_t capacity;
  size_t size;
  LinearAllocator *allocator;
} HashTable;
void hashtable_init(HashTable *table, size_t capacity,
                    LinearAllocator *allocator);
void hashtable_free(HashTable *table);
void hashtable_insert(HashTable *table, const char *key, void *value);
void *hashtable_get(HashTable *table, const char *key);
void hashtable_del(HashTable *table, const char *key);

#endif
