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

	deleted = delete_dnode_top(stk, ln);
	/* printf("deleted = %d\n", deleted); */
}

/**
 * delete_dnode_top - deleted the top element
 * @stk: double pointer to head of stack
 * @ln: line number
 *
 * Return: the deleted element on success
 */
int delete_dnode_top(stack_t **stk, unsigned int ln)
{
	int n;

	if (!*stk)
	{
		dprintf(STDERR_FILENO, POP_FAIL, ln);
		exit(EXIT_FAILURE);
	}
	n = (*stk)->n;
	*stk = (*stk)->next;
	if (*stk)
		(*stk)->prev = NULL;
	return (n);
}
