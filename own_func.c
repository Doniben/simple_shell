#include "header.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference between the compare
 */
int _strcmp(char *s1, char *s2)
{
	int n = 0;

	while (s1[n] && s2[n])
	{
		if (s1[n] != s2[n])
		{
			return (s1[n] - s2[n]);
		}
		n++;
	}
	return (s1[n] - s2[n]);
}

/**
 * _strdup - a function that returns a pointer to/
 * a newly allocated space in memory, which contains/
 * a copy of the string given as a parameter.
 *
 * @str: string
 *
 * Return: NULL if str equal NULL,/
 * a pointer to a new string which is a duplicate of the string str.
 */
char *_strdup(char *str)
{
	char *a;
	unsigned int i = 0;
	unsigned int j;

	if (str == 0)
		return (NULL);
	while (str[i])
		i++;
	i++;
	a = malloc(i * sizeof(char));
	if (a == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		a[j] = str[j];
	return (a);
}

/**
 * _strlen - returns the lenght of a string
 * @s: the pointer
 * Return: return the value to success
 */
int _strlen(char *s)
{
	int n = 0;

	while (s[n] != '\0')
		n++;

	return (n);
}

/**
 * *_strcat - Concat two strings
 * @dest: The string that receives
 * @src: The second string that receives
 *
 * Return: On success.
 */

char *_strcat(char *dest, char *src)
{
	int q = 0;
	int x = 0;
	char *concat = NULL;

	q = _strlen(dest);
	dest[q] = '/';
	q++;
	while (src[x])
	{
		dest[q] = src[x];
		x++;
		q++;
	}
	dest[q] = '\0';
	concat = malloc((q + 2) * sizeof(char));
	if (!concat)
	{
		free(concat);
		return (NULL);
	}
	concat = dest;
	return (concat);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
