#include "header.h"

/**
 * path_av - comunicate the route with the command
 *
 * @argv: argument
 *
 * Return: char double pointer to execute
 */
char **path_av(char **arg)
{
        int i = 0, counter = 0;
        char **p_1, **p = NULL;
        char *ruta = NULL;
        char *ph = NULL;
        struct stat buf;

        ph = getenv("PATH");
	counter = number_of_dir(ph);

        printf("%d\n", counter);

        p = (char**)malloc(sizeof(char*) * (counter));
        if (!p)
        {
                free(p);
                return (NULL);
        }
	p_1 = ph_to_dp(ph);
	p = conc_slash(p_1);

	printf("%s\n", p[0]);
	printf("%s\n", p_1[0]);

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
 * @token: tokenized string
 *
 * Return: The double pointer
 */
char **ph_to_dp(char *ph)
{
	char **p;
	int i = 0;

	p = (char **)malloc(sizeof(char *) * 9);
	if(!p)
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

/**
 * conc_slash - concatenate a slash
 *
 * @p: double pointer without slash
 *
 * Return: the double pointer with the slash in each pointer
 */
char **conc_slash(char **p)
{
	int i = 0, len = 0;

        while (p[i])
        {
		len = strlen(p[i]);
		p[len] = "/";
                i++;
        }

	return (p);
}
