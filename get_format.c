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

va_list get_format(const char *str, int i, va_list ls)
{
	int letter_i = 0;
	char letter[] = {'c', 's', 'd', 'i', 'b'};

	va_list (*func[])(va_list) = {
				print_char, print_s, print_int, print_int, binary};
	va_list ls2;

	while (str[i + 1] != letter[letter_i] && letter_i < sizeof(letter))
		letter_i++;

	va_copy(ls2, func[letter_i](ls));
	return (ls2);
}
