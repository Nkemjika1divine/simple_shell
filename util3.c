#include "main.h"



/**
 * not_path - this funcyion links commands that arnt aths with other functions
 * @input: user input
 * @argv: name of shell
 * @env: environmental variables
 */

void not_path(char *input, char **argv, char **env)
{
	char *token = NULL, *tokens[10], *n = NULL;
	int i = 0;

	token = _strtok(input, " ");
	while (token != NULL && i < 10 - 1)
	{
		tokens[i++] = token;
		token = _strtok(NULL, " ");
	}
	tokens[i] = NULL;

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
		else
			error_message(argv, input);
	}
	else
	{
		error_message(argv, input);
		exit(127);
	}
}
