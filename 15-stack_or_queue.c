#include "monty.h"

/**
 * queue_operation - sets the format of the data to a queue(FIFO).
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The top of the stack becomes the front of the queue
 *
 * Author: Gamachu AD
 */
void queue_operation(queue_t **stk, unsigned int ln)
{
	(void)stk;
	(void)ln;
	data.qflag = 1; /*Set qflag to 1 to indicate queue format*/
	/*the format change will have effect only on push operation*/
	/*which is handled in 0-push_and_pall.c file*/

}

/**
 * add_at_tail - adds a new element at the end of the queue
 * @que: double pointer to the front of the queue
 * @num: integer to be added
 *
 * Description: handles push operation when the format of
 * the data is in queue mode
 * Return: address of the inserted element
 */
queue_t *add_at_tail(queue_t **que, int num)
{
	queue_t *tmp = NULL;

	tmp = add_at_head(que, num); /*Inserts element at front*/
	rotl_operation(que, num); /*Shifts the front node to tail*/
	/*the second argument is not used, so we can*/
	/*ignore the fact I passed num for ln*/
	return (tmp);
}

/**
 * stack_operation - sets the format of the data to a stack (LIFO)
 * @stk: double pointer to the head(top) of the stack
 * @ln: the line number
 *
 * Description: This is the default behaviour of program.
 * When switching mode, the front of the queue becomes the top of the stack.
 *
 */
void stack_operation(stack_t **stk, unsigned int ln)
{
	(void)stk;
	(void)ln;
	data.qflag = 0; /*Sets the qflag to its default value of 0*/
}
