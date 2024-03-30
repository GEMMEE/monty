#include "monty.h"

/**
 * rotl_operation - rotates the stack to the top
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The top element of the stack becomes the last one, and
 * the second top element of the stack becomes the first one
 * the operation never fails
 *
 * Author: Gamachu AD
 */
void rotl_operation(stack_t **stk, unsigned int ln)
{
	int len;
	stack_t *temp = *stk;

	(void)ln;
	len = get_len(stk);
	if (len > 1)
	{
		while (temp->next)
			temp = temp->next;

		/*Insert top element at last*/
		temp->next = *stk;
		*stk = (*stk)->next;
		(*stk)->prev = NULL;
		temp->next->next = NULL;
		temp->next->prev = temp;
	}
}
