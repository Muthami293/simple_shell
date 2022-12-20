#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
 * test_strcat - tests the _strcat function
 *
 * This function tests the _strcat function for the following cases:
 * - Concatenating two strings
 * - Concatenating a string to an empty string
 *
 * The function uses the assert macro to check if the returned value of
 * _strcat is equal to the expected value. If the returned value is not
 * equal to the expected value, the assert macro will cause the program to
 * terminate with an error message.
 */
void test_strcat(void)
{
	char dest[6] = "Bet";
	char *src = "ty";
	char *expected = "Betty";

	assert(strcmp(_strcat(dest, src), expected) == 0);

	char dest_edge[6] = "";
	char *src_edge = "This string is too long to fit in the dest buffer";
	char *expected_edge = "This string is too long to fit in the dest buffer";

	assert(strcmp(_strcat(dest_edge, src_edge), expected_edge) == 0);

	return (0);
}

