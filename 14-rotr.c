#include "monty.h"

/**
 * rotr_operation - rotates the stack to the bottom
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The last element of the stack becomes
 * the top element of the stack
 * the operation never fails
 *
 * Author: Gamachu AD
 */
void rotr_operation(stack_t **stk, unsigned int ln)
{
	int len;
	stack_t *temp = *stk;

	(void)ln;
	len = get_len(stk);
	if (len > 1)
	{
		/*Make temp point to the last node*/
		while (temp->next)
			temp = temp->next;

		/*Make the next to last node the last node*/
		temp->prev->next = NULL;

		/*Move the last node to top*/
		temp->next = *stk;
		(*stk)->prev = temp;
		temp->prev = NULL;
		*stk = temp;
	}
}
