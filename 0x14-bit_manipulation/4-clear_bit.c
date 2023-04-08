#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number containing the bit.
 * @index: Index of the bit to clear.
 *
 * Return: 1 if successful, -1 otherwise.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= (sizeof(unsigned long int) * 8))
        return (-1);

    unsigned long int mask = 1 << index;
    *n &= ~mask;

    return (1);
}
