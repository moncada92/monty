#include "monty.h"
/**
 * opcode_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool opcode_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool argument_check(char *token)
{
	unsigned int i;
	printf("token: %s \n", token);

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @file: file content text
 *
 * Return: Nothing.
*/
void push_check(line_t line, char *opcode, FILE *file)
{
	printf("%s \n", argument_check(line.content[1]));
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		argint = atoi(line.content[1]);
}
