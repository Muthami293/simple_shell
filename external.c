#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"


/**
 * _getenv - searches for an env variable with the
 *           specified name.
 * @name: pointer to specified name.
 * Return: value of the specified name, otherwise NULL.
 */

char *_getenv(const char *name)
{
	int i;
	int len;

	len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			return (environ[i] + len);
		}
	}
	return (NULL);
}

/**
 * _strdup - duplicates a given string.
 *
 * @str: string param.
 * Return: duplicate of string.
 */

char *_strdup(const char *str)
{
	size_t i, len;
	char *copy;

	len = _strlen(str);

	copy = malloc(len + 1);

	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		copy[i] = str[i];
	}
	return (copy);
	free(copy);
}
/**
 * generate_path - generate a path for a command.
 *
 * @command: command to generate path for.
 * Return: command path generated,
 *         NULL if command path couldn't be generated,
 *         or if command was not found in path.
 */

char *generate_path(char *command)
{
	char *path, *path_copy, *command_path, *token;
	int command_len, dir_len;

	path = _getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path);

		command_len = _strlen(command);

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			dir_len = _strlen(token);

			command_path = malloc(command_len + dir_len + 2);

			if (command_path == NULL)
			{
				perror("Error");
			}

			_strcpy(command_path, token);
			_strcat(command_path, "/");
			_strcat(command_path, command);
			_strcat(command_path, "\0");

			if (access(command_path, F_OK) == 0)
			{
				return (command_path);
			}
			free(command_path);
			token = strtok(NULL, ":");
		}
	}
	return (NULL);
}
