#include "main.h"

/**
 * *print_int - a function to convert decimal number to binary.
 * @str: format string.
 * @i: index.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

void  print_int(const char *str, int i, va_list ls)
{
	long int num = va_arg(ls, int);
	char *s = intToString(num);

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
	_put(&str[i], ls);
}
