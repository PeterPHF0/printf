#include "main.h"

/**
 * _put - print string
 *
 * @str: format string.
 * @ls: argument list.
 *
 * Return: lenth of string
 */

void _put(const char *str, va_list ls)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				char c = '%';

				write(1, &c, 1);
				i += 2;
				continue;
			}
			get_format(str, i, ls);
			return;
		}
		write(1, &str[i], 1);
		i++;
	}
}
