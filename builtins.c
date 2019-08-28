#include "header.h"

/**
 * environment - function that prints the environmental variables
 *
 * @arg: tokenized argument
 *
 * Return: void
 */
void _environment(void)
{
	int i = 0;
	char *envt = *environ;

	while (envt)
	{
		write(STDIN_FILENO, envt,_strlen(envt));
		write(STDIN_FILENO, "\n",1);
		envt = environ[i];
		i++;
	}
}

/**
 * _exit - exit the shell
 *
 * Return: void
 */
void _ext(void)
{
 	exit(1);
}
