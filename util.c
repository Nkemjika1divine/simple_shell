#include "main.h"

/**
 * _putchar - writes chatacyer to stdout
 * @c: the character to write
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * spaces - this function checks a string for spaces and null characters.
 * @input: string to check
 *
 * Return: 1 if the string is just spaces and 0 if not
 */

int spaces(char *input)
{
	if (input == NULL)
		return (1);

	while (*input != '\0')
	{
		if (!is_space(*input))
			return (0);
		input++;
	}
	return (1);
}


/**
 * is_space - this function checks if a character is a whitespace
 * @c: character to check
 *
 * Return: 1 if character is a whitespace and 0 if not
 */

int is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
		c == '\r')
		return (1);
	else
		return (0);

	return (1);
}

