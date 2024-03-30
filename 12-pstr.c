#include "monty.h"

/**
 * pstr_operation - prints the string starting at the top of the stack + \n.
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The integer stored in each element of the stack is treated as
 * the ascii value of the character to be printed
 * The string stops when either:
 * 1. the stack is over
 * 2. the value of the element is 0
 * 3. the value of the element is not is the ascii table
 * If the stack is empty, prints only a new line
 *
 * Author: Gamachu AD
 */
void pstr_operation(stack_t **stk, unsigned int ln)
{
	stack_t *temp = *stk;

	(void)ln;
	if (!temp) /*stack is empty*/
	{
		printf("\n");
		return;
	}
	while (temp && temp->n && isascii(temp->n))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
