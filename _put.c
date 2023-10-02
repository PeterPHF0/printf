#include "main.h"

/**
 * _putchar - print char ch to stdout library.
 *
 * @ch: the printed character.
 *
 * Return: `1` indicates ch was successfully written to stdout.
 */

int _putchar(int ch)
{
	static int k;
	static char buf[OUTPUT_BUF_SIZE];

	if (k >= OUTPUT_BUF_SIZE || ch == BUF_FLUSH)
	{
		write(1, buf, k);
		k = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buf[k] = ch;
		k = k + 1;
	}
	return (1);
}

/**
 * _puts - prints a string with newline.
 *
 * @str: a string to print.
 *
 * Return: the length of the string that was printed.
 */

int _puts(char *str)
{
	char *ptr = str;

	while (*str)
		_putchar(*str++);
	return (str - ptr);
}
