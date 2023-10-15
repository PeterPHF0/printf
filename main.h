#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *intToString(int num);
<<<<<<< HEAD
void print_char(const char *str, int i, va_list ls);
void print_s(const char *str, int i, va_list ls);
void print_int(const char *str, int i, va_list ls);
int *generate_array(int num);
int get_arr_len(int *arr);
void binary(const char *str, int i, va_list ls);
va_list get_format(const char *str, int i, va_list ls);
=======
char *print_char(va_list ls);
char *print_s(va_list ls);
int *print_int(va_list ls);
int *generate_array(int num);
int get_arr_len(int *arr);
int *binary(va_list ls);
void *get_format(const char *str, int i, va_list ls);
>>>>>>> 4ec2aa4d484ad13cae84f973b08d386cb33dc452
void _put(const char *str, va_list ls);
int _printf(const char *format, ...);

#endif
