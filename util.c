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
