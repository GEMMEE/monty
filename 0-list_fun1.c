#include "monty.h"

/**
 * add_dnodeint_beg - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element,
 *         NULL if it failed
 */
dlistint_t *add_dnodeint_beg(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev =  NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_dlistint - prints a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
