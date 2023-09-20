#include "main.h"

/**
* get_width - Calculates the width
* @format: Formatted string in which to print the arguments.
* @j: List of arguments.
* @list: list of arguments.
* Return: width.
*/
int get_width(const char *format, int *j, va_list list)
{
int k;
int width = 0;
for (k = *j + 1; format[k] != '\0'; k++)
{
if (is_digit(format[k]))
{
width *= 10;
width += format[k] - '0';
}
else if (format[k] == '*')
{
k++;
width = va_arg(list, int);
break;
}
else
break;
}
*j = k - 1;
return (width);
}

