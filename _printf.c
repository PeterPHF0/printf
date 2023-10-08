#include "main.h"

/**
 * _printf - printf function
 *
 * @format: format string.
 *
 * Return: lenth of string
 */

int _printf(const char *format, ...)
{
	va_list ls;

	va_start(ls, format);

	const char *str;

	int size = 0;

	str = format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			continue;
		}
	size++;
	str++;
	}

	_put(format, ls);
	return (size);
}
