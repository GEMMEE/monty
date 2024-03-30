#include "monty.h"

data_t data = DATA_INIT;

/**
 * monty - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function that
 * will find the corresponding executing function
 *
 */
void monty(args_t *args)
{
	size_t len = 0;
	int read = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->ln++;
		read = getline(&(data.line), &len, data.fptr);
		if (read < 0)
			break;
		data.token = _strtok(data.line, " \n");
		/* task 10 is handled here: *(data.token) == '#' */
		/* If the first non-space character of a line is #, then */
		/* treat this line as a comment(don't do anything) */
		if (data.token == NULL || *(data.token) == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.token);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->ln, data.token);
			free_all(1), exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->ln);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 * Author: Gamachu AD
 */
int main(int argc, char **argv)
{
	args_t args;

	args.av = argv[1];
	args.ac = argc;
	args.ln = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
