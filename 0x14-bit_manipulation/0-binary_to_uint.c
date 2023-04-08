#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars representing a binary number
 *
 * Return: the converted number, or 0 if b is NULL or contains non-binary chars
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decimal;

	decimal = 0;
	if (b == NULL)
		return (0);
	
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		decimal <<= 1;
		if (b[i] == '1')
			decimal += 1;
	}

	return (decimal);
}
