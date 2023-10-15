#include "main.h"

/**
 * *print_int - a function to convert decimal number to binary.
 * @str: format string.
 * @i: index.
 * @ls: argument list.
 *
 * Return: ls after printing the value.
 */

<<<<<<< HEAD
void  print_int(const char *str, int i, va_list ls)
=======
int *print_int(va_list ls)
>>>>>>> 4ec2aa4d484ad13cae84f973b08d386cb33dc452
{
	int num = va_arg(ls, int);
	char *s = intToString(num);

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
	_put(&str[i], ls);
}
