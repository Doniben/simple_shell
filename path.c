#include "header.h"

/**
 * path_av - comunicate the route with the command
 *
 * @arg: argument
 *
 * Return: char double pointer to execute
 */
char **path_av(char **arg)
{
	int i = 0, counter = 0;
	char **p = NULL;
	char *ruta = NULL;
	char *ph = NULL;
	struct stat buf;

	ph = getenv("PATH");
	counter = number_of_dir(ph);

	p = (char **)malloc(sizeof(char *) * (counter));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	p = ph_to_dp(ph);

	while (p[i])
	{
		ruta = strcat(p[i], arg[0]);
		if (stat(ruta, &buf) == 0)
			return (p);
		i++;
	}
	return (p);
}

/**
 * ph_to_dp - function to put a path route into a double pointer
 *
 * @ph: tokenized string
 *
 * Return: The double pointer
 */
char **ph_to_dp(char *ph)
{
	char **p;
	int i = 0;

	p = (char **)malloc(sizeof(char *) * 9);
	if (!p)
		return (NULL);

	p[0] = strtok(ph, ":\n");
	i = 1;
	while (p[i])
	{
		p[i] = strtok(NULL, ":\n");
		i++;
		if (p[i] == NULL)
			break;
	}

	return (p);
}

/**
 * number_of_dir - number of directories in the tokenized string
 *
 * @ph: pointer to the tokenized string
 *
 * Return: integer with the number of directory
 */
int number_of_dir(char *ph)
{
	int counter = 0, counter_1 = 0;

	while (ph[counter_1] != '\0')
	{
		if (ph[counter_1] == ':')
			counter++;
		counter_1++;
	}
	counter++;

	return (counter);
}
