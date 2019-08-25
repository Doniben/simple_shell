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

        while (dest[q])
                q++;
        dest[q] = '/';

        while (src[x])
        {
                dest[q] = src[x];
                x++;
                q++;
        }

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
