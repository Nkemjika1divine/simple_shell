#include "main.h"

/**
 * _strtok - this function breaks characters into tokens
 * @str: string to break
 * @delim: the delimeter
 *
 * Returns: tokens
 */

char *_strtok(char *str, char *delim)
{
	static char* current_str = NULL;
	char* token_start = NULL, *ptr = NULL;

	if (str != NULL)
		current_str = str;

	if (current_str == NULL || *current_str == '\0')
		return (NULL);

	token_start = current_str;
	while (*current_str != '\0')
	{
		ptr = delim;
		while (*ptr != '\0')
		{
			if (*current_str == *ptr)
			{
				*current_str = '\0';
				current_str++;
				return (token_start);
			}
			ptr++;
		}
		current_str++;
	}
	return (token_start);
}
