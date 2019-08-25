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
	int i = 0;
	char *tok = NULL;
	char *ph = NULL;
	char *std_conc;
	struct stat *veri_stat = NULL;
	char **arg_1 = NULL;

	ph = getenv("PATH");
	tok = strtok(ph, ":");
	arg_1 = &std_conc;

	while (tok != NULL)
	{
		std_conc = _strcat(ph, arg[0]);
		stat(std_conc, veri_stat);
		if (veri_stat == NULL)
			return (arg_1);
		else if (veri_stat != NULL)
			i++;
		i++;
	}
	return (arg_1);
}

/**
 * exec_process - execution of process
 * @argv: argument
 *
 * Return: void
 */
void exec_process(char **path)
{
	pid_t pid = 0;
	int status = 0;
	int ver_exe;

	pid = fork();
	if (pid == 0)
	{
		ver_exe = execve(path[0], path, NULL);
		if (ver_exe == -1)
			perror("hsh: Error with execution doni");
	}
	else if (pid < 0)
		perror("hsh: Command doesn't exist");
	else
		wait(&status);
}

/**
 * parsing_argv - tokenize and analize the argument
 *
 * @line: argument without tokenize
 *
 * Return: char double pointer of the token
 */
char **parsing_arg(char *line)
{
	int bufsize = BUFSIZE;
	int pos = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	token = NULL;
	if (!tokens)
	{
		fprintf(stderr, "hsh: No such file or directory\n");
		free(tokens);
	}
	token = strtok(line, "  \n");
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if (pos >=  bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "hsh: Allocation error\n");
				free(tokens);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[pos] = NULL;
	return (tokens);
}

/**
 * read_line - print the line
 *
 * Return: pointer of type char in the input
 */
char *read_line(void)
{
	char prompt[3] = "$ ";
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;
	int i = 0;

	while (prompt[i] != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}
	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		perror("hsh: No such file or directory\n");
		free(line);
		exit(-1);
	}
	return (line);
}
