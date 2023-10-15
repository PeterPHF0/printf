#include "main.h"

/**
 * get_format - print string.
 *
 * @str: format string.
 * @i: index.
 * @ls: argument list.
 *
 * Return: lenth of string.
 */

<<<<<<< HEAD
void get_format(const char *str, int i, va_list ls)
=======
void *get_format(const char *str, int i, va_list ls)
>>>>>>> 4ec2aa4d484ad13cae84f973b08d386cb33dc452
{
	int letter_i = 0;
	char letter[] = {'c', 's', 'd', 'i', 'b'};

	void (*func[])(const char *, int, va_list) = {
				print_char, print_s, print_int, print_int, binary};

	while (str[i + 1] != letter[letter_i] && letter_i < sizeof(letter))
		letter_i++;

	func[letter_i](str, i + 2, ls);
}
