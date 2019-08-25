#include "header.h"

/**
 * main - Entry point
 *
 * Return: 0 to success
 */
int main(void)
{
	char *line = NULL;
	char **arg = NULL;
	char **path = NULL;
	int flag = 0;

	while (flag != EOF)
	{
		line = read_line();
		arg = parsing_arg(line);
		path = path_av(arg);
		exec_process(path);
		free(line);
		free(arg);
		free(path);
	}
	return (0);
}
