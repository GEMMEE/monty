#include "monty.h"

int is_int(const char *);

/**
 * push - implements push opcode
 * @stk: double pointer to top of the stack
 * @ln: line number
 *
 * Author: Gamachu AD
 */
void push(stack_t **stk, unsigned int ln)
{
	stack_t *node = NULL;
	char *arg = strtok(NULL, " \n");

	if (!arg || !is_int(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(*node));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(arg);
	node->prev = NULL;
	node->next = *stk;
	if (*stk)
		(*stk)->prev = node;
	*stk = node;
}

/**
 * pall - implements pall opcode
 * @stk: double pointer to the top of stack
 * @ln: line number
 *
 * Author: Gamachu AD
 */
void pall(stack_t **stk, unsigned int ln)
{
	stack_t *temp = *stk;

	(void)ln;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * is_int - checks if argument is an integer
 * @str: pointer to argument to check
 *
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
