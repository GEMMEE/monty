#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

/**
 * main - Monty ByteCode interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Return: EXIT_SUCCESS on success,
 *         EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(MAX_LINE_LENGTH);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;

		/* Process the line and execute the corresponding instruction */
		if (strcmp(line, "push\n") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		else if (strncmp(line, "push ", 5) == 0)
		{
			int value = atoi(line + 5);
			if (value == 0 && line[5] != '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(line, "pall\n") == 0)
		{
			pall(&stack);
		}

		/* If an unknown instruction is encountered, handle the error. */
		else 
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, line);
			free_stack(stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * push - pushes an element to the stack
 * @stack: a double pointer to the stack
 * @value: the value to be pushed
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack, starting fom the top of the stack
 * @stack: a double pointer to the stack
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack nodes.
 * @stack: a pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
