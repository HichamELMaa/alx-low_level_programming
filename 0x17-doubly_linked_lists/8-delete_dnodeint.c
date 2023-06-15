#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes node at a given index of a dlistint_t
 * @head: Pointer to the pointer to the head of the list
 * @index: Index of the node to be deleted (starting from 0)
 *
 * Return: 1 if deletion succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp != NULL && index > 0)
	{
		temp = temp->next;
		index--;
	}

	if (temp == NULL)
		return (-1);

	temp->prev->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
