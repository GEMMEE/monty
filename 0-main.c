#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	FILE *file;
	ssize_t rd;
	size_t bufsize = 0;
	unsigned int line_no = 0;
	char *line, *opcode = NULL;
	int i, found = 0;
	stack_t *stack = NULL;
	instruction_t inst[3] = {{"push", push}, {"pall", pall}, {NULL, NULL}};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((rd = getline(&line, &bufsize, file)) != -1)
	{
		line_no++;
		opcode = strtok(line, " \n");
		if (opcode == NULL)
			continue;
		for (i = 0; inst[i].opcode != NULL; i++)
		{
			if (!strcmp(opcode, inst[i].opcode))
			{
				found = 1;
				inst[i].f(&stack, line_no);
				break;
			}
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
		free(line), fclose(file), exit(EXIT_FAILURE);
	}
	return (0);
}
