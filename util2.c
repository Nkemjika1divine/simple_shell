#include "main.h"

/**
 * _strncpy - copy a string
 * @dest: destination string
 * @src: source string
 * @n: lenght of string
 *
 * Return: destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}




/**
 * _strdup - this function duplicates a string
 * @str: string to duplicate
 *
 * Return: a new string
 */

char *_strdup(const char *str)
{
	int i, length;
	char *dup;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	dup = (char *)malloc(length + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		dup[i] = str[i];

	return (dup);
}




/**
 * _memcpy - this functiom copies memory area
 * @dest: where it is stored
 * @src: where is it copied from
 * @n: number of bytes
 *
 * Return: copied memory wuth n bytes changed
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0, i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}

	return (dest);
}




/**
 * _strcpy - this function copies contebt of a string
 * @dest: destknation string
 * @src: sourse stribg
 *
 * Return: the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int l = 0, x = 0;

	while (*(src + l) != '\0')
		l++;

	for ( ; x < l ; x++)
		dest[x] = src[x];
	dest[l] = '\0';

	return (dest);
}




/**
 * _strlen - lenght of a string
 * @s: the string
 *
 * Return: lenght of the string
 */

int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
