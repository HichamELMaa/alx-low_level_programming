#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Size is not grandeur, and territory does not make a nation'
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	
        char c;
	int i;
	long li;
	long long lli;
	float f;

	printf("Size of a char: %i byte(s)\n", sizeof(c));
	printf("Size of an int: %i byte(s)\n", sizeof(i));
	printf("Size of a long int: %i byte(s)\n", sizeof(li));
	printf("Size of a long long int: %i byte(s)\n", sizeof(lli));
	printf("Size of a float: %i byte(s)\n", sizeof(f));
	return (0);
}
