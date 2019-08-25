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
        int j = 0;
        int counter = 0;
        char **tmp = 0;
        char **token = NULL;
        char **p = NULL;
	char *ruta = NULL;
        char *ph = NULL;
	struct stat *buf = NULL;

        p = (char**)malloc(sizeof(char*) * (i));
        ph = getenv ("PATH");
        while (ph[counter] != NULL)
        {
                if (ph == ':')
                        counter++;
        }
	counter++;

	token = strtok(ph, ':');
	while (token[i] != NULL)
	{
		while (token[i][j] != NULL)
		{
			tmp += token;
			j++;
			tmp[i][j] = '/';
			ruta = _strcat(tmp, arg[0]);
			
			if (stat(ruta, buf) == 0)
				return (p);
			else
				tmp = 0;
			i++;
		}
	}
	return (p);
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
