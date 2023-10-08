#include "main.h"

/**
 * *print_int - a function to convert decimal number to binary.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

va_list print_int(va_list ls)
{
	int num = va_arg(ls, int);
	char *s = intToString(num);

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
return (ls);
}
