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
	const char *str;
	int size = 0;

	va_start(ls, format);
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
