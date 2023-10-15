#include "main.h"

/**
 * *print_s - a function to print string.
 * @str: argument list.
 * @i: index.
 * @ls: ksa.
 * Return: ls after printing the value.
 */

<<<<<<< HEAD
void print_s(const char *str, int i, va_list ls)
=======
char *print_s(va_list ls)
>>>>>>> 4ec2aa4d484ad13cae84f973b08d386cb33dc452
{
	char *s = va_arg(ls, char *);

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
	_put(&str[i], ls);
}
