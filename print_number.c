#include <main.h>

/**
 * _isdigit - checks if
 * @c: the check
 * Return: 1 if
 */

int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
int longi = 0;
while (*s++)
{
longi++;
}
return (longi);
}

/**
 * print_number - prints
 * @str: the base
 * @params: parameter struct
 * Return: chars
 */
int print_number(char *str, params_t *params)
{
unsigned int i = _strlen(str);

int neg = (!params->unsign && *str == '-');

if (!params->precision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
i--;
}
if (params->precision != UINT_MAX)
while (i++ < params->precision)
*--str = '0';

if (neg)
*--str = '-';

if (!params->minus_flag)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}
