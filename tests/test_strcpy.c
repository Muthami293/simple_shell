#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
 * test_strcpy - tests the _strcpy function
 *
 * This function tests the _strcpy function for the following cases:
 * - Copying a string with multiple characters
 * - Copying a string with a null terminator in the middle of the string
 * - Copying a string to a buffer that is not large enough to hold it
 *
 * The function uses the assert macro to check if the returned value of
 * _strcpy is equal to the expected value. If the returned value is not
 * equal to the expected value, the assert macro will cause the program to
 * terminate with an error message.
 */
void test_strcpy(void)
{
	char dest[6];
	char *src = "Betty";
	char *expected = "Betty";

	assert(strcmp(_strcpy(dest, src), expected) == 0);

	char *src_edge = "Bet\0ty";
	char *expected_edge = "Bet";

	assert(strcmp(_strcpy(dest, src_edge), expected_edge) == 0);

	char *src_edge2 = "This string is too long to fit in the dest buffer";
	char *expected_edge2 = "This string is too long to fit in the dest buffer";

	assert(strcmp(_strcpy(dest, src_edge2), expected_edge2) == 0);
}
