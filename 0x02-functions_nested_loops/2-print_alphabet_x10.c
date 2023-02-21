#include "main.h"

/**
 * a function that prints 10 times the alphabet,
 * in lowercase,
 * 
 *
 * Return: void (no return)
 */
void print_alphabet_x10(void)
{
	char a;
	int i = 0;

	while (i < 10)
	{
	for (a = 'a'; a <= 'z'; a++)
	{
		_putchar(a);
	}
	_putchar('\n');
	i++;
	}
}
