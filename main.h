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
 * @specifier: format token
 * @f: the function associated
 */
typedef struct specifier
{
char *specifier;
int (*f)(va_list, params_t *);
} specifier_t;

/* params.c */
void init_params(params_t *params, va_list ptr);

/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list ptr);

/* _put.c */
int _puts(char *str);
int _puthchar(int c);

/* _pritnf.c program */
int _printf(const char *format, ...);

/* print_functions.c*/
int print_char(va_list ptr, params_t *params);
int print_string(va_list ptr, params_t *params);
int print_percent(va_list ptr, params_t *params);
int print_int(va_list ptr, params_t *params);
int print_S(va_list ptr, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ptr, params_t *params);
int print_address(va_list ptr, params_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list ptr, params_t *params);
int get_print_func(char *s, va_list ptr, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ptr);

/* convert_number.c */
int print_hex(va_list ptr, params_t *params);
int print_HEX(va_list ptr, params_t *params);
int print_binary(va_list ptr, params_t *params);
int print_octal(va_list ptr, params_t *params);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ptr, params_t *params);
int print_rot13(va_list ptr, params_t *params);

/* print_number.c  */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(va_list *ptr, params_t *params);
int print_number_left_shift(va_list *ptr, params_t *params);

#endif
