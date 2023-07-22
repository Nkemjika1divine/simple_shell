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
	/*Compare characters until one string ends*/
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (0); /*different strings*/
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (1);
	else
		return (0);
}
