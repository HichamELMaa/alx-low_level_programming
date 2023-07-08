#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/**
 * struct KeyValuePair - Structure for a key-value pair
 * @key: The key of the pair
 * @value: The value associated with the key
 */
typedef struct KeyValuePair
{
    char *key;
    char *value;
    struct KeyValuePair *next;
} KeyValuePair;

/**
 * @size: The size of the hash table array
 * @array: An array of pointers to KeyValuePair elements
 */
typedef struct hash_table_s
{
    unsigned long int size;
    KeyValuePair **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLE_H */
