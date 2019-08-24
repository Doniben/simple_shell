#include "header.h"

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
