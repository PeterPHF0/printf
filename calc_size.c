#include "main.h"

/**
 * get_size - Calculates the size.
 * @format: Formatted string.
 * @m: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *m)
{
int k = *m + 1;
int size = 0;
if (format[k] == 'l')
size = S_LONG;
else if (format[k] == 'h')
size = S_SHORT;
if (size == 0)
*m = k - 1;
else
*m = k;
return (size);
}

