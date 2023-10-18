#include "main.h"

/**
 * plus_dig_func - for +d +i specifier
 * @list: param
 *
 * Return: string len
 */
int plus_dig_func(va_list list)
{
	int numLen = -1;
	int a = va_arg(list, int);
	int isPos = 0;

	if (a > 0)
	{
		_putchar('+');
		isPos = 1;
	}

	if (a <= INT_MAX && a >= INT_MIN)
	{
		numLen = print_number(a);
	}

	return (isPos ? numLen + 1 : numLen);
}

/**
 * plus_ptr_func - for +p specifier
 * @list: param
 *
 * Return: string len
 */
int plus_ptr_func(va_list list)
{
	int num;

	_putchar('+');

	num = ptr_func(list);

	return (num + 1);
}
