#include "main.h"

/**
 * get_endianness - Checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x = 0x01;
	char *c = (char *)&x;

	if (*c == 0x01)
		return (1);
	else
		return (0);
}
