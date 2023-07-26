#include "main.h"

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



/**
 * newstring - this function concatenates content of char array
 * @array: the array to concatenate
 * @size: size of the array
 *
 * Return: the nee string
 */

char *newstring(char *array[], int size)
{
	int i, total_len;
	char *string;

	if (size == 0)
	{
		string = (char *)malloc(1);
		if (string == NULL)
		{
			if (write(2, "Memory allocation error\n",
				_strlen("Memory allocation error\n")) < 0)
				perror("write");
			exit(EXIT_FAILURE);
		}
		string[0] = '\0';
		return (string);
	}

	total_len = calculate_length(array, size);
	string = (char *)malloc(total_len + 1);
	if (string == NULL)
	{
		if (write(2, "Memory allocation error\n",
			_strlen("Memory allocation error\n")) < 0)
			perror("write");
		exit(EXIT_FAILURE);
	}
	string[0] = '\0';

	for (i = 0; i < size; i++)
	{
		_strcat(string, array[i]);
		if (i < size - 1)
			strcat(string, " ");
	}

	return (string);
}




/**
 * calculate_length - calculates lenght of string to be created
 * @array: the array of strings which the strngs will be calculated
 * @size: size of the array
 *
 * Return: lenght of the potential string
 */

int calculate_length(char *array[], int size)
{
	int i, separator;
	size_t length = 0;

	for (i = 0; i < size; i++)
	{
		if (length > SIZE_MAX - _strlen(array[i]))
		{
			if (write(2, "Integer overflow detected in length\n",
				_strlen("Integer overflow detected in length\n")) < 0)
				perror("write");
			exit(EXIT_FAILURE);
		}
		length += _strlen(array[i]);
	}

	separator = size - 1;
	if (length > SIZE_MAX - separator)
	{
		if (write(2, "Integer overflow detected in length\n",
			_strlen("Integer overflow detected in length\n")) < 0)
			perror("write");
		exit(EXIT_FAILURE);
	}
	length += separator;

	return (length);
}





/**
 * error_message - prints error message
 * @argv: the argument vector
 * @input: user input
 */

void error_message(char **argv, char *input)
{
	char *err = "not found\n", *ptr = NULL, *output = NULL;
	int argv_len, input_len, err_len, total_len;

	argv_len = _strlen(argv[0]);
	input_len = _strlen(input);
	err_len = _strlen(err);
	total_len = argv_len + input_len + err_len + 7;

	output = (char *)malloc(total_len + 1);
	if (output == NULL)
		return;

	ptr = output;
	_memcpy(ptr, argv[0], argv_len);
	ptr += argv_len;
	*ptr = ':';
	ptr++;
	*ptr = ' ';
	ptr++;
	_memcpy(ptr, "1", 1);
	ptr++;
	*ptr = ':';
	ptr++;
	*ptr = ' ';
	ptr++;
	_memcpy(ptr, input, input_len);
	ptr += input_len;
	*ptr = ':';
	ptr++;
	*ptr = ' ';
	ptr++;
	_memcpy(ptr, err, err_len);
	ptr += err_len;
	*ptr = '\0'; /* Null-terminate the string */

	if (write(2, output, total_len) < 0)
		perror("write");
	free(output);
}
