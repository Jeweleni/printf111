#include "main.h"

/**
 * octal_func - base 8
 * @list: list args
 * Return: from convert
 */
int octal_func(va_list list)
{
	unsigned long int num = va_arg(list, unsigned int);
	int a = convert(num, 8, 0, 1);

	return (a);
}
/**
 * stringupperCase_func - replace non printable
 * @list: list args
 * Return: length
 */
int stringupperCase_func(va_list list)
{
	char *s = va_arg(list, char *);
	int i = 0;
	int count = 0;

	if (s == NULL)
		return (write(1, "(null)", 6));

	if (s[i] < 0)
		s[i] = s[i] * -1;

	while (s[i] != '\0')
	{
		if (!(s[i] >= 32 && s[i] < 127))
		{
			_putchar('\\');
			_putchar('x');

			if (s[i] >= 0 && s[i] <= 15)
			{
				_putchar('0');
			}

			convert(s[i], 16, 1, 0);

			count += 4;
		}
		else
		{
			_putchar(s[i]);
			count++;
		}
		i++;
	}

	return (count);
}
/**
 * hex_lower_func - base 16
 * @list: list args
 * Return: value
 */
int hex_lower_func(va_list list)
{
	int num = va_arg(list, unsigned int);

	num = convert(num, 16, 0, 0);

	return (num);
}
/**
 * rev_func - base 16
 * @list: list args
 * Return: value
 */
int rev_func(va_list list)
{
	char *s = va_arg(list, char *);
	int size = 0, i = 0;

	while (s[size] != '\0')
		size++;

	for (i = size - 1; i >= 0; i--)
		_putchar(s[i]);

	return (size);
}

/**
 * rot13_func - rot13 encryption of strings
 * @list: string to encrypt
 *
 * Return: encrypted string
 */
int rot13_func(va_list list)
{
	char *s = va_arg(list, char *);

	char ref[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char src[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (ref[j] != '\0')
		{
			if (s[i] == ref[j])
			{
				_putchar(src[j]);
				break;
			}
			j++;
		}

		if (s[i] != ref[j])
			_putchar(s[i]);

		i++;
	}

	return (i);
}
