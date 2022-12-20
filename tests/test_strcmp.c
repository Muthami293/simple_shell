#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "shell.h"

/**
  * test_strcmp - tests the _strcmp function.
  *
  * This function tests the strcmp function for three cases:
  * - if _strcmp correctly returns 0 when the two strings being
  *   compared are the same.
  * - if _strcmp correctly returns -1 when the two strings being
  *   compared have different characters but are in different cases.
  * - if _strcmp correctly returns the ASCII value of the first
  *   character that differs when the two strings being compared
  *   have different characters and the first string is an empty string.
  *
  * The function uses the assert function to check if the returned value of
  * _strcmp is equal to the expected result. If the returned value is not
  *  equal to the expected result,
  *  the assert function will terminate the program.
 */

void test_strcmp(void)
{
	char *s1 = "hello";
	char *s2 = "hello";
	int expected = 0;

	assert(_strcmp(s1, s2) == expected);

	char *s1_edge = "AaBbCcDd";
	char *s2_edge = "aAbBcCdD";
	int expected_edge = -1;

	assert(_strcmp(s1_edge, s2_edge) == expected_edge);

	char *s1_edge2 = "";
	char *s2_edge2 = "aAbBcCdD";
	int expected_edge2 = -97;

	assert(_strcmp(s1_edge2, s2_edge2) == expected_edge2);

	return (0);
}
