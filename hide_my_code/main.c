#include "monty.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> /* for isspace function */

#define MAX_LINE_LENGTH 1024

/**
 * trim_spaces - trims leading and trailing spaces from a string
 * @str: string
 * Return: pointer to trimmed string
 */
char *trim_spaces(char *str)
{
	char *end = NULL;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

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
		char *trimmed_line = trim_spaces(line);
		char opcode[MAX_LINE_LENGTH];
		int argument;

		if (sscanf(trimmed_line, "%s %d", opcode, &argument) == 2)
		{
			if (strcmp(opcode, "push") == 0)
				push(&stack, argument);
		}
		else if (sscanf(trimmed_line, "%s", opcode) == 1)
		{
			if (strcmp(opcode, "pall") == 0)
				pall(&stack);
		}
		else if (strcmp(trimmed_line, "push") == 0)
		{
			print_push_error(line_number);
		}
		else
		{
			print_unknown_instruction_error(line_number, trimmed_line);
		}
	}
	fclose(file);
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}
