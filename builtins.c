#include "header.h"

/**
 * _enviro - function that prints the environmental variables
 *
 * Return: void
 */

void _enviro(void)
{
	int i = 0;
	char *envt = *environ;

	while (envt)
	{
		write(STDIN_FILENO, envt, _strlen(envt));
		write(STDIN_FILENO, "\n", 1);
		envt = environ[i];
		i++;
	}
}

/**
 * salto_linea - function for the use of signal
 * @n: void parameter
 * Return: void
 */
void salto_linea(int n)
{
	(void)n;

	write(STDOUT_FILENO, "\n", 1);
}
