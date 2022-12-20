#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * handle_exit - handles exit command.
 *
 * @command: command passed to execute function.
 * Return: 1 if the given command is exit, O otherwise.
 */

int handle_exit(char *command)
{
	return (_strcmp(command, "exit") == 0);
}

/**
 * handle_env - handles env command.
 *
 * @command: command passed to execute function.
 * Return: 1 if the given command is env, O otherwise.
 */

int handle_env(char *command)
{
	return (_strcmp(command, "env") == 0);
}

/**
 * print_env - prints all environment variables.
 *
 * Return: void.
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		_puts(*env);
		env++;
	}
}
