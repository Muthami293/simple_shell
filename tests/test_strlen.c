#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
 * test_strlen - tests the _strlen function
 *
 * This function tests the _strlen function for the following cases:
 * - Calculating the length of a string with multiple characters
 * - Calculating the length of an empty string
 *
 * The function uses the assert macro to check if the returned value of
 * _strlen is equal to the expected value. If the returned value is not
 * equal to the expected value, the assert macro will cause the program to
 * terminate with an error message.
 */
void test_strlen(void)
{
	char *s = "Betty";
	int expected = 5;

	assert(_strlen(s) == expected);

	char *s_edge = "";
	int expected_edge = 0;

	assert(_strlen(s_edge) == expected_edge);

	return (0);
}
