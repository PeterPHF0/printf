#include<stdio.h>
/**
 * main - Entry point
 *
 * Description: use sizeof
 *
 * Return: 0 (Success)
*/

int has_specifier(const char* format)
{
	int i = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
			return (i);
		i++;
	}
	return (-1);

}

void replace_specifier(const char* format, int i, ...)
{
	va_list args;
	int specifier_char_i = i + 1;
	char *str;

	va_start(args, i);

	switch (format[specifier_char_i])
	{
		case 'c':
			putchar(va_arg(args, char));
			break;
		case 's':
			str = va_arg(args, char *);
			while (*str != '\0')
			{
				putchar(*str);
				str++;
			}
			break;
		case '%':
			putchar('%'):
			break;
		default:
			putchar(format[i]);
			break;
	}
}
