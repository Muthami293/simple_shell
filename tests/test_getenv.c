#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
  * test_getenv - tests the behavior of the _getenv function.
  * It is testing two cases:
  * The first case tests if _getenv correctly returns
  * the value of the environment variable with the name "USER".
  * The second case tests if _getenv correctly returns
  * NULL when the specified environment variable does not exist.
  *
  * The function uses the assert function to check
  * if the returned value of _getenv is equal to the expected result.
  * If the returned value is not equal to the expected result,
  * the assert function will terminate the program.
 */

void test_getenv(void)
{
	char *name = "USER";
	char *expected = "Shell";

	assert(strcmp(_getenv(name), expected) == 0);

	char *name_edge = "This variable does not exist";
	char *expected_edge = NULL;

	assert(_getenv(name_edge) == expected_edge);
}

