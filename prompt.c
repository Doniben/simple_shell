#include "header.h"

/**
 * path_av - comunicate the route with the command
 *
 * @argv: argument
 *
 * Return: char double pointer to execute
 */
char **path_av(char **argv)
{
	int i = 0;
	int j = 0;
	char tok = 0;
	char ph = 0;


	ph = getenv("PATH");
	tok = strtok(ph , ":");
	
	while (argv[0] == ph[i])
	{
		while (tok != NULL)
			i++;
		while (argv != NULL)
				j++;
		tok = argv;
		strtok(NULL, ":");
	}
	return (argv);
}

/**
 * exec_process - execution of process
 * @argv: argument
 *
 * Return: void
 */
void exec_process(char **argv)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, NULL);
	else if (pid < 0)
		perror("Error");
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
char **parsing_argv(char *line)
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
		if (pos >= bufsize)
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
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;

	printf("$ ");
	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		perror("hsh: No such file or directory\n");
		free(line);
		exit(-1);
	}

	return (line);
}

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

	}
	return (0);
}
