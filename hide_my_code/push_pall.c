#include "monty.h"

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

