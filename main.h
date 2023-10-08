#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *intToString(int num);
va_list print_char(va_list ls);
va_list print_s(va_list ls);
va_list print_int(va_list ls);
int *generate_array(int num);
int get_arr_len(int *arr);
va_list binary(va_list ls);
va_list get_format(const char *str, int i, va_list ls);
void _put(const char *str, va_list ls);
int _printf(const char *format, ...);

#endif
