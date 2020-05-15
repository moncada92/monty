#include "monty.h"

/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line contents and line number
 * @file: file content text
 * Return: pointer to the matching function
 */

void (*get_op_func (line_t line, FILE *file))(stack_t **, unsigned int)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line, ops[i].opcode, file);
			return (ops[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free(line.content);
	exit(EXIT_FAILURE);
}
