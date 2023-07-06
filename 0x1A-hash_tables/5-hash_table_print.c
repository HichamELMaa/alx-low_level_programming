#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints the key-value pairs in a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const HashTable *ht)
{
    unsigned long int i;
    int flag = 0;
    KeyValuePair *current_node;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        current_node = ht->array[i];
        while (current_node != NULL)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", current_node->key, current_node->value);
            flag = 1;
            current_node = current_node->next;
        }
    }
    printf("}\n");
}
