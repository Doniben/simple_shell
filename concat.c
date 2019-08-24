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

	while (*(dest + q))
	{
		q++;
	}
	while (*(src + x))
	{
		*(dest + q) = *(src + x);
		x++;
		q++;
	}
	return (dest);
}
