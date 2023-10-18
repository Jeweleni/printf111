#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>

/**
 * struct LoopReturn - loop return
 * @count: member 1
 * @i: member 2
 */
typedef struct LoopReturn
{
	int count;
	int i;
} LoopReturn;

/**
 * struct Choice - name of struct for choosing function
 * @specifier: format specifier
 * @f: pointer to function to call
 */
typedef struct Choice
{
	char *specifier;
	int (*f)(va_list list);
} Choice;

int _printf(const char *format, ...);

/* helper_functions  */
int width_func(va_list list, int width, int flag, char match, Choice choice[]);
int _putchar(char c);
int print_char(va_list list);
int ptr_func(va_list list);
int plus_func_num(va_list list);
int plus_func_ptr(va_list list);
LoopReturn nextFuncton(const char *current, Choice check, int i, va_list list);
int get_function(const char *format, va_list list, Choice choice[], int size);

/* helper.4 */
int print_int_func(int num);
int space_func_num(va_list list);
int space_func_ptr(va_list list);
int mod_octal_func(va_list list);
int mod_hex_func(va_list list);

/* helper.3 */
int octal_func(va_list list);
int stringupperCase_func(va_list list);
int hex_lower_func(va_list list);
int rev_func(va_list list);
int rot13_func(va_list list);

/* helper2.c */
int convert(unsigned long a, int base, int flag_upper, int flag_ptr);
int percent_func(__attribute__((unused)) va_list list);
int binary_func(va_list list);
int unsig_int_func(va_list list);
int hex_upper_func(va_list list);

/* helper1.c */
int digit_func(va_list list);
int print_number(long n);
int _putchar(char c);
int char_func(va_list list);
int str_func(va_list list);

/* helper5.c */
int plus_dig_func(va_list list);
int plus_ptr_func(va_list list);

#endif
