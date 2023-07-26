#include "main.h"

/**
 * main - this is the entry point of the shell program
 * @argc: argument count
 * @argv: argument vector
 * @env: environmental variables
 *
 * Return: o
 */

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		prompt(argv, env);
	return (0);
}


/**
 * prompt - Exexution if the executable file is entered on the command line
 * @argv: argument vector
 * @env: environmental variables
 */

void prompt(char **argv, char **env)
{
	char *prompt = "$ ", *input = NULL;
	size_t input_size = 0;
	int i, finput = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			/*prompt*/
			for (i = 0; i < 2; i++)
				_putchar(prompt[i]);
		}
		/*Accept user input*/
		if (getline(&input, &input_size, stdin) < 0)
		{
			if (!finput)
			{
				free(input);
				finput = 1;
			}
			break;
		}
		if (spaces(input) != 1)
		{
			i = 0;
			while (input[i])
			{
				if (input[i] == '\n')
					input[i] = 0;
				i++;
			}
			format_str(input, argv, env);
			free(input);
			input = NULL;
		}
		free(input);
		input = NULL;
	}
	if (!finput)
		free(input);
}


/**
 * format_str - this function breaks down the input string for processing
 * @input: user input
 * @argv: argument vector
 * @env: emvironmemtal variables
 */

void format_str(char *input, char **argv, char **env)
{
	char *token, *n, *s = "/";
	char *tokens[10]; /**c[] = {"cd", "env", "exit", "alias"};*/
	int i = 0;

	/*Use strtok to tokenize the input string*/
	token = strtok(input, " ");
	while (token != NULL && i < 10 - 1)
	{
		tokens[i++] = token;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	if (tokens[0][0] != s[0])
	{
		tokens[0] = paths(tokens[0]);
		if (tokens[0] != NULL)
		{
			n = newstring(tokens, i);
			if (n != NULL)
			{
				exec(n, argv, env);
				free(tokens[0]);
				free(n);
			}
		}
		else
			error_message(argv, input);
	}
	else
	{
		if (access(tokens[0], X_OK) == 0)
		{
			n = newstring(tokens, i);
			if (n != NULL)
				exec(n, argv, env);
		}
		else
			error_message(argv, input);
	}
}






/**
 * checkpath - thus function checks if the file without the oath exists
 * @str: the strung to check
 *
 * Return: the new string
 */

char *checkpath(char *str)
{
	DIR *dir = opendir("/bin/");
	char *temp, *cats;
	struct dirent *entry;

	if (dir == NULL)
		return (NULL);

	entry = readdir(dir);
	while (entry != NULL)
	{
		temp = entry->d_name;
		if (str_cmp(temp, str) == 1)
		{
			cats = _strcat("/bin/", str);
			closedir(dir);
			return (cats);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}


/**
 * exec - this function executes the processes
 * @input: the input string
 * @argv: argument vector
 * @env: environmental variables
 */

void exec(char *input, char **argv, char **env)
{
	int i, status;
	char *vec[10];
	pid_t pid;

	i = 0;
	vec[i] = strtok(input, " ");
	while (vec[i])
		vec[++i] = strtok(NULL, " ");

	/*create processes*/
	pid = fork();

	if (pid < 0)
	{
		printf("Error in fork");
		free(input);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(vec[0], vec, env) == -1)
		{
			error_message(argv, input);
			exit(127);
		}
	}
	else
		wait(&status);
}
