#include "header.h"

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
