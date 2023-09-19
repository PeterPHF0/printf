#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
int sum = 0;
va_list ptr;
char *p, *start;
params_t params = PARAMS_INIT;

va_start(ptr, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_params(&params, ptr);
if (*p != '%')
{
sum += _putchar(*p);
continue;
}
start = p;
p++;
while (get_flag(p, &params))
{
p++;
}
p = get_width(p, &params, ptr);
p = get_precision(p, &params, ptr);
if (get_modifier(p, &params))
p++;
if (!get specifier(p))
sum += print_from_to(start, p,
	params.l_modifier || params.h_modifier ? p - 1 : 0);
else
sum += get_print_func(p, ptr, &params);
}
_putchar(BUF_FLUSH);
va_end(ptr);
return (sum);
}

