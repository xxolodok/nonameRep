#include "hashTable.h"
#include "linearAlloc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint32_t hash_func(const char *str) {
  uint32_t hash = 5381;
  while (*str) {
    hash = ((hash << 5) + hash) + (uint8_t)(*str);
    str++;
  }
  return hash;
}

void hashtable_init(HashTable *table, size_t capacity,
                    LinearAllocator *allocator) {
  if (!table || !allocator || capacity == 0)
    return;

  table->capacity = capacity;
  table->size = 0;
  table->allocator = allocator;

  table->items = linear_alloc(allocator, sizeof(HashTableItem) * capacity);
  memset(table->items, 0, sizeof(HashTableItem) * capacity);
}

void hashtable_free(HashTable *table) {
  if (!table)
    return;

  table->items = NULL;
  table->capacity = 0;
  table->size = 0;
  table->allocator = NULL;
}

static int find_slot(HashTable *table, const char *key, size_t *out_index,
                     int for_insert) {
  if (!table || !key || table->capacity == 0)
    return 0;

  uint32_t hash = hash_func(key);
  size_t index = hash % table->capacity;

  size_t start_index = index;
  size_t first_deleted = -1;

  while (1) {
    HashTableItem *item = &table->items[index];

    if (!item->is_occupied) {
      if (for_insert) {
        // Если нашли удалённый слот ранее, используем его
        if (first_deleted != -1) {
          *out_index = (size_t)first_deleted;
        } else {
          *out_index = index;
        }
        return 1;
      } else {
        // Для поиска - ключа нет
        return 0;
      }
    } else if (item->key && strcmp(item->key, key) == 0) {
      // Ключ найден
      *out_index = index;
      return 1;
    }

    index = (index + 1) % table->capacity;
    if (index == start_index)
      break; // Обошли всю таблицу
  }

  // Если для вставки, но таблица полна
  if (for_insert && first_deleted != -1) {
    *out_index = (size_t)first_deleted;
    return 1;
  }

  return 0;
}

void hashtable_insert(HashTable *table, const char *key, void *value) {
  if (!table || !key || table->capacity == 0)
    return;
  if (table->size >= table->capacity)
    return;

  size_t index;
  int found = find_slot(table, key, &index, 1);
  if (!found)
    return;

  HashTableItem *item = &table->items[index];

  if (item->is_occupied) {
    item->value = value;
    return;
  }

  size_t key_len = strlen(key) + 1;
  char *key_copy = linear_alloc(table->allocator, key_len);
  if (!key_copy)
    return;

  memcpy(key_copy, key, key_len);

  item->key = key_copy;
  item->value = value;
  item->is_occupied = 1;
  table->size++;
}

void *hashtable_get(HashTable *table, const char *key) {
  if (!table || !key || table->capacity == 0)
    return NULL;

  size_t index;
  int found = find_slot(table, key, &index, 0);

  if (!found)
    return NULL;

  HashTableItem *item = &table->items[index];
  if (item->is_occupied)
    return item->value;

  return NULL;
}

void hashtable_del(HashTable *table, const char *key) {
  if (!table || !key || table->capacity == 0)
    return;

  size_t index;
  int found = find_slot(table, key, &index, 0);

  if (!found)
    return;

  HashTableItem *item = &table->items[index];
  if (item->is_occupied) {
    item->is_occupied = 0;
    item->key = NULL;
    item->value = NULL;
    table->size--;
  }
}
