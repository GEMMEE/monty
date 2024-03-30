#include "monty.h"


/**
 * get_func - selects the right function
 * @opcode: pointer to the 1st token from the bytecode file
 *
 * Return: pointer to the selected function,
 *         NULL on failure
 */
void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_arr[] = {
		{"push", push_operation},
		{"pall", pall_operation},
		{"pint", pint_operation},
		{"pop", pop_operation},
		{"swap", swap_operation},
		{"add", add_operation},
		{"nop", nop_operation},
		{"sub", sub_operation},
		/*{"div", div_operation},*/
		/*{"mul", mul_operation},*/
		/*{"mod", mod_operation},*/
		{NULL, NULL}
	};

	int i, num_operation = sizeof(op_arr) / sizeof(op_arr[0]);

	for (i = 0; i < num_operation - 1; i++)
	{
		if (!strcmp(op_arr[i].opcode, opcode))
			return (op_arr[i].f);
	}
	return (NULL);
}
