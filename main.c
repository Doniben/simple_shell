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
	char **path = NULL;
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
		path = path_av(arg);
		exec_process(path);
		free(line);
		free(arg);
		free(path);
	}
	return (0);
}
