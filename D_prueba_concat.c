#include "header.h"

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

	while (dest[q])
		q++;

	while (src[x])
	{
		dest[q] = src[x];
		x++;
		q++;
	}
	return (dest);
}

int main(void)
{
	char str_1[20] = "Doniben y ";
	char str_2[] = "Nicolás";
	char *concat;

	concat = _strcat(str_1, str_2);
	printf("%s\n", concat);
	return (0);
}
