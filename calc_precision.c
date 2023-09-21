#include "main.h"

/**
 * get_precision - Calculate vsdv sdv s the precision
 * @format: Fo dvsd dsv sdsvrmatted string in which to print the arguments
 * @j: List of argumen to be prin df vted.
 * @list: li menfvdf bts.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
int k = *j + 1;
int precision = -1;
if (format[k] != '.')
return (precision);
precision = 0;
for (k += 1; format[k] != '\0'; k++)
{
if (is_digit(format[k]))
{
precision *= 10;
precision += format[k] - '0';
}
else if (format[k] == '*')
{
k++;
precision = va_arg(list, int);
break;
}
else
break;
}
*j = k - 1;
return (precision);
}
