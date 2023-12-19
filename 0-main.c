#include "monty.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

/**
 * trim_spaces - trims leading and trailing spaces
 * @str: the string passed
 * Return: the trimmed string
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
 * process_line - processes the line
 * @trimmed_line: the trimmed line
 * @line_number: the line number
 * @stack: the stack
 */
void process_line(char *trimmed_line, unsigned int line_number,
		stack_t **stack)
{
	char opcode[MAX_LINE_LENGTH];
	int argument;
	int matches = sscanf(trimmed_line, "%s %d", opcode, &argument);

	if (matches == 2 && strcmp(opcode, "push") == 0)
	{
		push(stack, argument);
	}
	else if (matches == 1)
	{
		if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
		else if (strcmp(trimmed_line, "push") == 0)
		{
			print_push_error(line_number);
		}
		else
		{
			print_unknown_instruction_error(line_number,
							trimmed_line);
		}
	}
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char *line = malloc(MAX_LINE_LENGTH);
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		print_usage_error();
	if (!file)
		print_file_open_error(argv[1]);
	if (!line)
		print_malloc_error();
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		process_line(trim_spaces(line), line_number, &stack);
	}
	fclose(file);
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}

