#include "main.h"

/**
 * *print_char - a function to print a character.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

char *print_char(va_list ls)
{
	char c = va_arg(ls, int);

	write(1, &c, 1);
	return (ls);
}
