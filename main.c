#include "header.h"

/**
 * main - Entry point
 *
 * Return: 0 to success
 */
int main(void)
{
	char w_env[4] = "env";
	char w_exit[5] = "exit";
	char *line = NULL;
	char **arg = NULL;
	int flag = 0;

	while (flag != EOF)
	{
		line = read_line();
		arg = parsing_arg(line);
		if (_strcmp(w_env, arg[0]) == 0)
		{
			_environment();
			continue;
		}
		else if (_strcmp(w_exit, arg[0]) == 0)
		{
			exit(1);
			continue;
		}
		exec_process(arg);
		free(line);
		free(arg);
	}
	return (0);
}
