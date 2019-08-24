#include "header.h"

/**
 * main - Entry point
 *
 * Return: 0 to success
 */
int main(void)
{
	char *line;
	char **argv;
	char **path;
	int flag = 0;

	while (flag != EOF)
	{
		line = read_line();
		argv = parsing_argv(line);
		path = path_av(argv);
		exec_process(path);
		free(line);
		free(argv);
		free(path);
	}
	return (0);
}
