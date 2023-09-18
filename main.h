#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define PARAMS_INIT (0,0,0,0,0,0,0,0,0,0)

/**
 * struct specifier - struct token/
 *
 *@specifier: format token
 *
 * @fun: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*fun)(va_list, params_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _puthchar(int c);

/* _pritnf program*/
int _printf(const char *format, ...);

/* print_functions.c*/
int print_char(va_list ptr, params_t *params);
int print_string(va_list ptr, params_t *params);
int print_percent(va_list ptr, params_t *params);
int print_int(va_list ptr, params_t *params);
