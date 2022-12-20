#include <stdlib.h>

/**
 * _strncmp - compares two strings.
 * @s1: initial string.
 * @s2: second string.
 * @n: number of characters to compare.
 * Return: 0 if the strings are equal.
 *          a positive number if s1 > s2.
 *          a negative number if s1 < s2.
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
