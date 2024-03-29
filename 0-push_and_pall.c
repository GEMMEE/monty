#include "monty.h"

int is_int(const char *);

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
		node = add_dnodeint_beg(stk, num);
	/* else if (data.qflag == 1) */
	/*	node = add_dnodeint_end(stk, num); */
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
		print_dlistint(*stk);
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
