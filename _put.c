#include "main.h"

/**
 * _putchar - char c to stdout library
 *
 * @c: the printed character
 *
 * Return: (1) on success and (-1) on error
 */

int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _puts - prints a string with newline
 *
 * @str: a string to print
 *
 * Return: nothing
 */

int _puts(char *str)
{
	char *ptr = str;

	while (*str)
		_putchar(*str++);
	return (str - ptr);
}
