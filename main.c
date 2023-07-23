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
	ssize_t a;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			/*prompt*/
			for (i = 0; i < 2; i++)
				_putchar(prompt[i]);
		}
		/*Accept user input*/
		a = getline(&input, &input_size, stdin);
		if (a < 0)
		{
			perror("getline");
			if (!finput)
			{
				free(input);
				finput = 1;
			}
			break;
		}
		if (spaces(input) != 1)
		{
			printf("%s", input);
			i = 0;
			while (input[i])
			{
				if (input[i] == '\n')
					input[i] = 0;
				i++;
			}
			exec(input, argv, env);
		}
	}
	if (!finput)
		free(input);
}


/**
 * exec - executes the processes
 * @input: user input
 * @argv: argument vector
 * @env: emvironmemtal variables
 */

/*void format_str(char *input, char **argv, char **env)
{
	int i;
	char *vec[] = {NULL, NULL};
	char *tokens[10];*/

	/*break input intk tokens*/
	/*vec[0] = strtok(input, " ");
	i = 0;
	while (vec[i] != NULL && i < 10)
	{
		tokens[i] = vec[i];
		i++;
		vec[i] = strtok(NULL, " ");
	}

	if (i > 0 && tokens[i - 1][0] == '-')
	{
		tokens[i - 1] = strcat(tokens[i - 1], " ");
		vec[0] = strtok(NULL, " ");
		while (vec[0] != NULL && i < 10)
		{
			tokens[i - 1] = strcat(tokens[i - 1], " ");
			vec[0] = strtok(NULL, " ");
		}
	}
	tokens[i] = NULL;
}*/



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
			printf("%s: %s No such file or directory", argv[0], input);
	}
	else
		wait(&status);
}
