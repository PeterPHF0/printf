#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: string to be printed
 *
 * Return: number of characters printed
 */
 
int _printf(const char *format, ...)
{
int i = 0, count = 0;
char *str;
va_list args;

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
str = va_arg(args, char*);
if (str == NULL)
{
str = "(null)";
}
while (*str != '\0')
{
putchar(*str);
str++;
count++;
}
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
putchar(format[i]);
count += 2;
}
}
else
{
putchar(format[i]);
count++;
}
}
va_end(args);
return (count);
}
