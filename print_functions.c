#include "main.h"
/**
 * print_char - prints character
 * @ptr: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_char(va_list ptr, params_t *params)
{
char pad_char = ' ';
unsigned int pad = 1, sum = 0, ch = va_arg(ptr, int);

if (params->minus_flag)
sum += _putchar(ch);
while (pad++ < params->width)
sum += _putchar(pad_char);
if (!params->minus_flag)
sum += _putchar (ch);
return (sum);
}

/**
 * print_string - prints string
 * @ptr: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
*/
int print_string(va_list ptr, params_t *params)
{
char *str = va_arg(ptr, char *), pad_char = ' ';
unsigned int pad = 0, sum = 0, i = 0, j;
(void)params;
switch ((int)(!str))
case l:
str = NULL_STRING;
j = pad = _strlen(str);
if (params->precision < pad)
j = pad = params->precision;
if (params->minus_flag)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
Sum += _putchar (*str++);
else
sum += _puts(str);
}
while (j++ < params->width)
sum += _putchar(pad_char);
if (!params->minus_flag)
{
if (params->precision != UINT_MAX)
for (i = 0; i < pad; i++)
sum += _putchar(*str++);
else
sum += _puts(str);
}
return (sum);
}

/**
 * print_percent - prints
 * @ptr: pointer to the argument
 * @params: struct of parameters
 * Return: number of printed chars
 */
int print_percent(va_list ptr, params_t *params)
{
(void)ptr;
(void)params;
return (_putchar('%'));
}

/**
 * print_int - prints integer
 * @ptr: pointer to the argument
 * @params: the parameters struct
 * Return: number chars printed
*/

int print_int (va_list ptr, params_t *params)
{
long l;
if (params->1_modifier)
l = va_arg(ptr, long);
else if (params->h_modifier)
l = (short int)va_arg(ptr, int);
else
l = (int)va_arg(ptr, int);
return (print_number(convert(1, 10, 0, params), params));
}
