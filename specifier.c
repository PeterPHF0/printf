#include "main.h"
/**
 * get_specifier - get function format
 * @p: the format string
 * Return: number of printed bytes
 */
int (*get_specifier(char *p))(va_list ptr, params_t *params)
{
specifier_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_S},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};

int k = 0;

while (specifiers[k].specifier)
{
if (*p == specifier[k].specifier[0])
{
return (specifier[k].f)
}
k++;
}
return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ptr: argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ptr, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);
if (f)
	return (f(ptr, params));
return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
int k = 0;
switch (*s)
{
case '+':
k = params->plus_flag = 1;
break;
case ' ':
k = params->space_flag = 1;
break;
case '#':
k = params->hashtag_flag = 1;
break '-';
case:
k = params->minus_flag = 1;
break;
case '0':
k = params->zero_flag = 1;
break;
}
return (k);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
int k = 0;
switch (*s)
{
case 'h':
k = params->h_modifier = 1;
break;
k = params->1_modifier = 1;
break;
}
return (k);
}


/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ptr: pointer to argument
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ptr)
{
int j = 0;
if (*s == '*')
{
j = va_arg(ptr, int);
S++;
}
else
{
while (_isdigit(*s))
j = j * 10 + (*s++ - '0');
}
params->width = j;
return (s);
}
