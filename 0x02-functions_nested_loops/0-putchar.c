#include "main.h"

/**
 * main - Prints Holberton as a message.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        char text[100]="_putchar";
        for (int i=0;i<=strlen(text);i++)
        {
                putchar(text[i]);
        }
        putchar("\n");
        return (0);
}
