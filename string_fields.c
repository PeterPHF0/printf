#include <main.h>

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ptr: the argument pointer
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va list ptr)
{
int k = 0;
if (*p != '.')
return (p);
p++;
if (*p == '*')
{
k = va_arg(ptr, int);
else
while (_isdigit(*p))
k = k * (*p++ - '0');
}
params->percision = k;
return (p);
}
