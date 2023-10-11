#include "main.h"

/**
 * *print_s - a function to print string.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

char *print_s(va_list ls)
{
	char *s = va_arg(ls, char *);

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
return (ls);
}
