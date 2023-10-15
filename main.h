#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *intToString(int num);
void print_char(const char *str, int i, va_list ls);
void print_s(const char *str, int i, va_list ls);
void print_int(const char *str, int i, va_list ls);
int *generate_array(int num);
int get_arr_len(int *arr);
void binary(const char *str, int i, va_list ls);
va_list get_format(const char *str, int i, va_list ls);
void _put(const char *str, va_list ls);
int _printf(const char *format, ...);

#endif
