#include "main.h"

/**
 * *print_char - a function to print a character.
 * @i: inedx.
 * @str: Foramt string.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

<<<<<<< HEAD
void print_char(const char *str, int i, va_list ls)
=======
char *print_char(va_list ls)
>>>>>>> 4ec2aa4d484ad13cae84f973b08d386cb33dc452
{
	char c = va_arg(ls, int);

	write(1, &c, 1);
	_put(&str[i], ls);
}
