#include "main.h"

int main(void)
{
	char* prompt = "$ ", *input = NULL;
	size_t input_size = 0;
	int a, i, finput = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			/*prompt*/
			for (i = 0; i < 2; i++)
				_putchar(prompt[i]);
		}

		/*Accept user input*/
		a = getline(&input, & input_size, stdin);
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
		printf("%s", input);

	}
	if (!finput)
		free(input);

	return (0);
}
