#include "monty.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		print_usage_error();
	file = fopen(argv[1], "r");
	if (!file)
		print_file_open_error(argv[1]);
	line = malloc(MAX_LINE_LENGTH);
	if (!line)
		print_malloc_error();
	while (fgets(line, MAX_LINE_LENGTH, file) && ++line_number)
	{
		if (strcmp(line, "push\n") == 0)
			print_push_error(line_number);
		if (strncmp(line, "push ", 5) == 0)
		{
			int value = atoi(line + 5);

			if (value == 0 && line[5] != '0')
				print_push_error(line_number);
			push(&stack, value);
		}
		else if (strcmp(line, "pall\n") == 0)
			pall(&stack);
		else
			print_unknown_instruction_error(line_number, line);
	}
	fclose(file);
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}
