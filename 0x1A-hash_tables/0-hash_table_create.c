#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if memory allocation fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hashTable = malloc(sizeof(hash_table_t));

	if (hashTable == NULL)
	{
		return (NULL);
	}

	hashTable->size = size;
	hashTable->array = malloc(size * sizeof(KeyValuePair *));

	if (hashTable->array == NULL)
	{
		free(hashTable);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		hashTable->array[i] = NULL;
	}

	return (hashTable);
}
