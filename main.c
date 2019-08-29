#include "header.h"

/**
 * main - entry point
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
	int exec = 0;

	signal(SIGINT, salto_linea);

	while (flag != EOF)
	{
		line = read_line();

		arg = parsing_arg(line);
		if (_strcmp(w_env, arg[0]) == 0)
		{
			free(line);
			free(arg);
			_enviro();
			continue;
		}
		else if (_strcmp(w_exit, arg[0]) == 0)
		{
			free(line);
			free(arg);
			exit(0);
			continue;
		}
		exec = exec_process(arg, line);
		if (exec == -1)
			continue;
		free(line);
		free(arg);
	}
	return (0);
}
