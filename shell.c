#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute_command - executes command passed to main.
 *
 * @argv: an array of pointer to arguments passed to main.
 * Return: 0 on success, 1 on failure.
 */

void execute_command(char **argv)
{
	char *command;
	char *path_command;
	pid_t pid;

	if (argv)
	{
		command = argv[0];
		path_command = generate_path(command);

		if (handle_exit(command))
		{
			exit(EXIT_SUCCESS);
		}
		else if (handle_env(command))
		{
			print_env();
		}
		else if (path_command)
		{
			pid = fork();

			if (pid == 0)
			{
				if (execve(path_command, argv, NULL) == -1)
				{
					perror("Error");
				}
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * main - a CLI that runs commands.
 * @argc: number of arguments passed.
 * @argv: pointer to array of arguments
 * Return: O on success, 1 on failure.
 */

int main(int argc, char **argv)
{
	char *input, *input_copy;
	size_t n = 0;
	ssize_t nread = 0;

	if (argc < 0)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 5);

		nread = getline(&input, &n, stdin);

		if (nread == -1)
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
		input_copy = malloc(sizeof(char) * nread);

		if (input_copy == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		_strcpy(input_copy, input);

		parse_input(input, input_copy, argv);
	}

	free(input_copy);
	return (EXIT_SUCCESS);
}
