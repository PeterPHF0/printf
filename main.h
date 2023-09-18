#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define NULL_STRING "(null)"

/**
* struct parameters - parameters struct
*
* @unsign: flag if unsigned value
*
* @plus_flag: on if plus flag specified
* @space_flag: on if hashtag flag specified
* @hashtag_flag: on if flag specified
* @zero_flag: on if flag specified
* @minus_flag: on if flag specified
*
* @width: field width specified
* @precision: field precision specified
*
* @h_modifier: on if h_modifier is specified
* @l_modifier: on if l modifier is specified
*/
typedef struct parameters
{
unsigned int unsign : 1;

unsigned int width : 1;
unsigned int precision : 1;

unsigned int plus_flag : 1;
unsigned int space_flag : 1;
unsigned int hashtag_flag : 1;
unsigned int zero_flag : 1;
unsigned int minus_flag : 1;

unsigned int h_modifier : 1;
unsigned int l_modifier : 1;
} params_t;

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
