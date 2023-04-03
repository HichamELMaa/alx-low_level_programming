#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t list and returns its data
 * @head: pointer to a pointer to the first node of the list
 *
 * Return: the data of the head node, or 0 if the list is empty
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

