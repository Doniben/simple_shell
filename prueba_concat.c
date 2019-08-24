#include "header.h"

/**
 * concat_two_std - concatenate two strings
 *
 * @argv: string of the argument
 * @ph: string of the route of PATH
 *
 * Return: string concatenated
 */
char *concat_two_std(char *argv, char *ph)
{
        int std_1 = 0;
        int std_2 = 0;
        char *std = NULL;
        int i = 0;

        std_1 = _strlen(argv);
        std_2 = _strlen(ph);

        std = malloc((std_1) + (std_2) * sizeof(char) + 2);
        if (!std)
        {
                free(std);
                return (NULL);
        }
        std = ph;
        while (std != NULL)
                i++;
        std[i] = '/';
        std = argv;

        return (std);
}

int main(void)
{
	char *argv_1;
	char *ph_1;
	char std_1 = "Donien y ";
	char std_2 = "Nicolás";
	char *concat;

	arg_1 = &std_1;
	ph_1 = &std_2;

	concat = concat_two_std(argv_1, ph_1);
	printf("%s", concat);
	return(0);
}
