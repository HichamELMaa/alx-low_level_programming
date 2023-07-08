#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in the hash table array
 * @key: The key used to calculate the index
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);
	unsigned long int index = hash_value % size;

	return (index);
}
