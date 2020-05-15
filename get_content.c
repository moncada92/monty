#include "monty.h"

/**
 * format_line - get lines the file
 * @line: text content the file
 * @buffer: content text no format the file
 * Return: void
 */

void format_line(char *buffer, line_t *line)
{
	char *token = NULL;
	int i;

	token = strtok(buffer, " '\n'");

	line->content = malloc(sizeof(char *) * strlen(token));

	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line->number = 0;

	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		line->number++;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;

}

/**
 * get_content - get lines the file
 * @file: file for get content
 *
 * Return: void
 */

void get_content(FILE *file)
{
	char *buffer = NULL;
	store_t *sotre_st = NULL;
	size_t l = 0;
	ssize_t read = 0;
	line_t line;

	buffer = malloc(sizeof(char *) * l);

	sotre_st = malloc(sizeof(store_t));
	if (!sotre_st)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &l, file)) != -1)
	{
		format_line(buffer, &line);
		get_op_func(line, file)(&(sotre_st->stack), line.number);
	}

	free(buffer);
	fclose(file);
}
