#ifndef _HT_H
#define _HT_H

#include <stdbool.h>
#include <stddef.h>


// Hash table structure: create with ht_create, free with ht_destroy
typedef struct ht ht;

// Create hash table
ht* ht_create(void);

// Free memory allocated for hash table, including allocated keys.
void ht_destroy(ht *table);

// Get item with given key (NUL-terminated) from hash table.
// Returning void as we can type cast later
void* ht_get(ht *table, const char *key);

// Set item with given key (NUL-terminated) to value (which must not be NULL).
const char* ht_set(ht *table, const char *key, void *value);

// Return number of items in table
size_t ht_length(ht *table);

// Hash table iterator: create with ht_iterator, iterate with ht_next.
typedef struct {
    const char *key;
    void *value;

    // Do not use these fields directly
    ht *_table;
    size_t _index;
} hti;

// Return new hash table iterator (for use with ht_next).
hti ht_iterator(ht* table);

// Move iterator to next item in hash table, update iterator's key and value to current item, and return true.
bool ht_next(hti* it);

#endif // _HT_H
