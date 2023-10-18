#include "main.h"

/**
 * digit_func - print normal digits
 * @list: list of args
 * Return: length
 */
int digit_func(va_list list)
{
	unsigned int m;
	int i = 0, k = 0, n = 0, count = 0;

	n = va_arg(list, int);
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
 * print_number - prints signed numbers
 * @n: parameter
 * Return: count
 */
int print_number(long n)
{
	static int count;

	unsigned int x = 0;

	if (n < 0)
	{
		n = n * -1;

		x = n;
		_putchar('-');
		count++;
	}
	else
		x = n;

	if (x / 10)
		print_number(x / 10);

	_putchar((x % 10) + '0');
	count++;

	return (count);
}

/**
 * _putchar - prints a char to stdout
 * @c: char to print
 *
 * Return: 1 if successful
 */
int _putchar(char c)
{
	int i = write(1, &c, 1);

	return (i);
}

/**
 * char_func - prints single char
 * @list: list of arguments
 *
 * Return: 1 if char is printed
 */
int char_func(va_list list)
{
	char c = va_arg(list, int);

	_putchar(c);

	return (1);
}
/**
 * str_func - prints single char
 * @list: list of arguments
 *
 * Return: 1 if char is printed
 */
int str_func(va_list list)
{
	char *s = va_arg(list, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
