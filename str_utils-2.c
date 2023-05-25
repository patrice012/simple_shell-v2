#include "header.h"

/**
 * _substr - extracts characters from source
 *			                between m and n.
 *
 * @src: string
 * @m: first character
 * @n: second character
 * Return: return string between m & n
 */
char *_substr(char *src, int m, int n)
{
	int len = n - m, i;
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 2));
	m--;

	for (i = m; i < n && (src[i] != '\0'); i++)
		ptr[i - m] = src[i];

	ptr[len + 1] = '\0';

	return (ptr);
}


/**
 * _atoi - convert string to integer
 * @str: string
 * Return: returns integer.
 * note: *10 is an indication if digit.
 */

int _atoi(char *str)
{
	int i = 0, sign = 1, result = 0;

	if (str == NULL)
		return (0);

	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	while (str[i] >= '0' && str[i] <= '9')
	{
		/* convert to integer */
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}


/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: integer less than/equal to/greater than if s1 is found
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * _strncmp - compares two strings until n
 *
 * @s1: first string
 * @s2: second string
 * @n: the first n length to compare
 *
 * Return: integer less than/equal to/greater than if s1 is found
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
