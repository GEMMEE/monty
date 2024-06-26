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

typedef stack_t queue_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"

#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_NOT_ASCII "L%u: can't pchar, value out of range\n"



/* main.c */
void monty(args_t *args);

/* get_func.c */
void (*get_func(char *opcode))(stack_t **, unsigned int);

/* free.c */
void free_all(int all);
void free_dlistint(stack_t *);

/* _strtok.c */
char *_strtok(char *s, const char *delim);

/* task 0: 0-push_and_pall.c */
void push_operation(stack_t **stack, unsigned int ln);
stack_t *add_at_head(stack_t **, const int);
void pall_operation(stack_t **stack, unsigned int ln);
size_t print_elements(const stack_t *);
int is_int(const char *);

/* task 1:  1-pint.c */
void pint_operation(stack_t **stk, unsigned int ln);
int get_top(stack_t **stk);

/* task 2:  2-pop.c */
void pop_operation(stack_t **stk, unsigned int ln);
int delete_top(stack_t **stk);

/* task 3:  3-swap.c */
void swap_operation(stack_t **stk, unsigned int ln);
int get_len(stack_t **stk);

/* task 4:  4-add.c */
void add_operation(stack_t **stk, unsigned int ln);

/* task 5:  5-nop.c */
void nop_operation(stack_t **stk, unsigned int ln);

/* task 6:  6-sub.c */
void sub_operation(stack_t **stk, unsigned int ln);

/* task 7:  7-div.c */
void div_operation(stack_t **stk, unsigned int ln);

/* task 8:  8-mul.c */
void mul_operation(stack_t **stk, unsigned int ln);

/* task 9:  9-mod.c */
void mod_operation(stack_t **stk, unsigned int ln);

/* task 10: handled in main.c */

/* task 11:  11-pchar.c */
void pchar_operation(stack_t **stk, unsigned int ln);

/* task 12:  12-pstr.c */
void pstr_operation(stack_t **stk, unsigned int ln);

/* task 13:  13-rotl.c */
void rotl_operation(stack_t **stk, unsigned int ln);

/* task 14:  14-rotr.c */
void rotr_operation(stack_t **stk, unsigned int ln);

/* task  15:  15-stack_or_queue.c */
void queue_operation(queue_t **que, unsigned int ln);
queue_t *add_at_tail(queue_t **que, int num);
void stack_operation(stack_t **stk, unsigned int ln);

#endif /* MONTY_H */
