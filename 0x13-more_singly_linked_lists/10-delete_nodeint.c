#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of a listint_t list.
 * @head: Pointer to a pointer to the first element of the listint_t list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if succeeded, -1 otherwise.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}

	previous = *head;
	current = previous->next;

	for (i = 1; current != NULL && i <= index; i++)
	{
		if (i == index)
		{
			previous->next = current->next;
			free(current);
			return (1);
		}

		previous = current;
		current = current->next;
	}

	return (-1);
}
