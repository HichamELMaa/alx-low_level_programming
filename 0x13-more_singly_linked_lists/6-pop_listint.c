#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * @head: a double pointer
 *
 *Return: empty
 */
int pop_listint(listint_t **head)
{
	listint_t *old_head;
	int data;

	if (*head == NULL)
		return (0);
	old_head = *head;
	*head = old_head->next;
	data = old_head->n;
	free(old_head);
	return (n);
}

