#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <signal.h>

extern int argint;

/**
 * struct f_line - contents of line and corresponding number
 * @content: array of tokens read from the line
 * @number: the line number
 *
 * Description: contents of a line and corresponding number
 */
typedef struct f_line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct store_s - doubly linked list representation of a stack (or queue)
 * @stack: content linked list
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct store_s
{
	stack_t *stack;
} store_t; 

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void get_content(FILE *file);
void format_line(char *buffer, line_t *line);

void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);


void (*get_op_func(line_t line, FILE *file))(stack_t **, unsigned int);

bool opcode_check(line_t line);
bool argument_check(char *token);
void push_check(line_t line, char *opcode, FILE *file);

#endif
