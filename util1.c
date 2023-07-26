#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src : source string
 *
 * Return: pointer to new string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * inputcheck - this function checks if 2 strings start the same way
 * @str1: the first string
 * @str2: the second string
 * @n: the number of characters to check
 *
 * Return: 0 if different and 1 if they are same
 */

int inputcheck(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (0);
		if (str1[i] == '\0')
			return (1);
	}
	return (1);
}


/**
 * str_cmp - this function compares two strings of any lenght to know if same
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 1 if they're the sane and 0 if different
 */

int str_cmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}



/**
 * _putchar - writes a characyer to stdout
 * @c: the charactr
 *
 * Return: 1 on success and -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}



/**
 * paths - checks if a path exists
 * @command: the commnd to check
 *
 * Return: full path if it exists
 */

char *paths(char *command)
{
	char *path[] = {
		"/usr/local/sbin/",
		"/usr/local/bin/",
		"/usr/sbin/",
		"/usr/bin/",
		"/sbin/",
		"/bin/"
	};
	int i, num = sizeof(path) / sizeof(path[0]);
	char full_path[256] = {0};

	for (i = 0; i < num; i++)
	{
		/*Concatenate the command with the current path*/
		_strcpy(full_path, path[i]);
		_strcat(full_path, command);
	}

	/*Check if the full path to the command is accessible*/
	if (access(full_path, X_OK) == 0) /*true*/
		return (_strdup(full_path));

	return (NULL); /*IF FALSE*/
}
