#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *intToString(int num);
char *print_char(va_list ls);
char *print_s(va_list ls);
int *print_int(va_list ls);
int *generate_array(int num);
int get_arr_len(int *arr);
int *binary(va_list ls);
void *get_format(const char *str, int i, va_list ls);
void _put(const char *str, va_list ls);
int _printf(const char *format, ...);

#endif
