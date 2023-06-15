#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - print all the elements of a doubly linked list
 * @h: pointer to the start of the linked list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->data);
		h = h->next;
	}
	return (i);
}
