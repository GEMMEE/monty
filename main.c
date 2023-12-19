#include "monty.h"
#include <ctype.h>


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
