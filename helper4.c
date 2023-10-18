#include "main.h"

/**
 * print_int_func - prints an integer
 * @n: integer to print
 *
 * Return: length of string printed
 */
int print_int_func(int n)
{
	int count = 0, m = 0, k = 0, i = 0;

	if (n < 0)
	{
		n *= -1;
		_putchar('-');
		count += 1;
	}
	m = n;
	for (k = 0; (m / 10) > 0; k++)
		m /= 10;

	m = n;
	while (k != 0)
	{
		for (i = 0; i < k; i++)
			m /= 10;
		m %= 10;
		_putchar(m + '0');
		count++;
		k--;
		m = n;
	}
	_putchar(m % 10 + '0');
	count++;

	return (count);
}
/**
 * space_func_num - space num
 * @list: list args
 * Return: num
 */
int space_func_num(va_list list)
{
	unsigned int m;
	int i = 0, k = 0, n = 0, count = 0;

	n = va_arg(list, int);
	if (n > 0)
	{
		_putchar(' ');
		count++;
	}
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n < 0)
		{
			n *= -1;
			_putchar('-');
			count += 1;
		}
		m = n;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;
		m = n;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = n;
		}
		_putchar(m % 10 + '0');
		count++;
	}
	else
	{
		return (-1);
	}
	return (count);
}

/**
 * space_func_ptr - space ptr
 * @list: list args
 * Return: num
 */
int space_func_ptr(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}

/**
 * mod_octal_func - space ptr
 * @list: list args
 * Return: num
 */
int mod_octal_func(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}

/**
 * mod_hex_func - octal func
 * @list: list args
 * Return: num
 */
int mod_hex_func(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}
