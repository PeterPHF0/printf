#include<main.h>
/**
 * main - Entry point
 *
 * Description: use sizeof
 *
 * Return: 0 (Success)
*/

void _printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format) {
		if (*format == '%') {
			format++; // Move to the character after '%'
			switch (*format) {
				case 'd': {
					int value = va_arg(args, int);
					printf("%d", value);
					break;
					  }
				case 's': {
					char* str = va_arg(args, char*);
					printf("%s", str);
					break;
					  }
				default:
					  putchar(*format);
			}
		} else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}



