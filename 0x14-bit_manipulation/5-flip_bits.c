#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from n to m.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
        unsigned int count = 0;
        unsigned long int flip = n ^ m;

        while (flip != 0)
        {
                if (flip & 1)
                        count++;

                flip = flip >> 1;
        }

        return (count);
}
