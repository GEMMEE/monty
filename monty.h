#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - structure of arguments from main
 * @av: name of the file from the command line
 * @ac: number of arguments from main
 * @ln: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int ln;
} args_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @token: parsed token
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 *
 */
typedef struct data_s
{
	char *line;
	char *token;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"

#define PINT_FAIL "L%u: can't pint, stack empty\n"


/* main.c */
void monty(args_t *args);

/* get_func.c */
void (*get_func(char *opcode))(stack_t **, unsigned int);
void push_operation(stack_t **stack, unsigned int ln);
void pall_operation(stack_t **stack, unsigned int ln);

/* free.c */
void free_all(int all);
void free_dlistint(dlistint_t *);

/* _strtok.c */
char *_strtok(char *s, const char *delim);

/* helper functions */
dlistint_t *add_dnodeint_beg(dlistint_t **, const int);
dlistint_t *add_dnodeint_end(dlistint_t **, const int);
size_t print_dlistint(const dlistint_t *);

/* task 1:  1-pint.c */
void pint_operation(stack_t **stk, unsigned int ln);
int get_dnode_top(stack_t **stk, unsigned int ln);


#endif /* MONTY_H */
