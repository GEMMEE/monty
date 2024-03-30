#include "monty.h"

/**
 * push_operation - implements push operation
 * @stk: double pointer to top of the stack to push to
 * @ln: number of the line in the file
 *
 * Author: Gamachu AD
 */
void push_operation(stack_t **stk, unsigned int ln)
{
	stack_t *node = NULL;
	int num;

	data.token = _strtok(NULL, " \n");
	if (!(data.token) || !is_int(data.token))
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	num = atoi(data.token);

	if (data.qflag == 0)
		node = add_at_head(stk, num);

	/*added later for task 15*/
	/*Handle case when the format of the data is a queue .ie. qflag = 1*/
	else if (data.qflag == 1)
		node = add_at_tail(stk, num);

	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_operation - implements pall opcode
 * @stk: double pointer to the top of stack
 * @ln: number of the line in the file
 *
 * Author: Gamachu AD
 */
void pall_operation(stack_t **stk, unsigned int ln)
{
	(void)ln;
	if (*stk)
		print_elements(*stk);
}

/**
 * is_int - checks if argument is an integer
 * @str: pointer to argument to check
 *
 * Description: helper for push_operation
 * Return: 1 if integer, 0 otherwise
 */
int is_int(const char *str)
{
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * add_at_head - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Description: helper for push_operation
 * Return: the address of the new element,
 *		   NULL if it failed
 */
stack_t *add_at_head(stack_t **head, const int n)
{
	stack_t *new;

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
 * print_elements - prints all elements of stack or queue
 * @h: pointer to the head
 *
 * Description: helper the pall_operation
 * Return: number of nodes in the list
 */
size_t print_elements(const stack_t *h)
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
