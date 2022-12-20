#include <stdlib.h>

/**
 * _strcmp - compares two strings.
 * @s1: initial string.
 * @s2: second string.
 * Return: 0 if the strings are equal.
 *          a positive number if s1 > s2.
 *          a negative number if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
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
