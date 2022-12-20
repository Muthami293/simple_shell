#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0
  */

int main(void)
{
	test_strcpy();
	test_strcat();
	test_strlen();
	test_strcmp();
	test_strncmp();
	test_getenv();

	return (0);
}
