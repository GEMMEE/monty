#include "monty.h"

/**
 * pop_operation - removes the top element of the stack
 * @stk: double pointer to the top of stack
 * @ln: the number of line in the bytecode file
 *
 * Author: Gamachu AD
 */
void pop_operation(stack_t **stk, unsigned int ln)
{
	int __attribute__((unused))deleted;

	if (!*stk)
	{
		dprintf(STDERR_FILENO, POP_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	deleted = delete_top(stk);
	/* printf("deleted = %d\n", deleted); */
}

/**
 * delete_top - deleted the top element
 * @stk: double pointer to head of stack
 *
 * Return: the deleted element on success
 */
int delete_top(stack_t **stk)
{
	int n;
	stack_t *temp;

	n = (*stk)->n;
	temp = (*stk)->next;
	free(*stk);
	*stk = temp;
	if (*stk)
		(*stk)->prev = NULL;
	return (n);
}
