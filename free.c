#include "monty.h"

/**
 * free_all - custom memory handling function
 * @all: flag to indicate what to free
 *
 */
void free_all(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		data.token = NULL;
	}
	if (all)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the head of the list
 *
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
