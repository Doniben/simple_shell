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
	int j = 0;

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
	char tok = 0;
	char **ph = NULL;
	char std_conc = 0;
	struct stat *veri_stat = NULL;
	int stat_n = 0;

	ph = getenv("PATH");
	tok = strtok(ph, ":");

	while (tok != NULL)
	{
		std_conc = concat_two_std(*argv, *ph);
		stat(std_conc, veri_stat);
		if (stat == 0)
			return (std_conc);
		else if (stat != 0)
			i++;
		i++;
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
