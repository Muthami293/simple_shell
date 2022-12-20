#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * parse_input - takes input from stdin and tokenizes
 *		it into an array of arguments
 * @input: a buffer that contains the input from stdin
 * @input_copy: a buffer for storing arguments.
 * @argv: an array of arguments
 * Return: the number of arguments parsed
 */

int parse_input(char *input, char *input_copy, char **argv)
{
	char *arg;
	int argc = 0, i = 0;

	arg = strtok(input, " \n");

	while (arg != NULL)
	{
		argc++;
		arg = strtok(NULL, " \n");
	}
	argc++;

	argv = malloc(sizeof(char *) * argc);

	if (argv == NULL)
	{
		free(argv);
		exit(EXIT_FAILURE);
	}

	arg = strtok(input_copy, " \n");

	for (i = 0; arg != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(arg));

		if (argv[i] == NULL)
		{
			free(argv[i]);
			exit(EXIT_FAILURE);
		}
		strcpy(argv[i], arg);

		arg = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	execute_command(argv);
	free(argv);
	return (i);
}
