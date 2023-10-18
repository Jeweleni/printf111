#include "main.h"
/**
 * ptr_func - handle pointers' addresses
 * @list: pointer to list arguments
 * Return: value
 */
int ptr_func(va_list list)
{
	int count = 0;
	uintptr_t ptr = (uintptr_t)va_arg(list, void *);

	if (ptr == 0)
	{
		char *s = "(nil)";

		while (s[count] != '\0')
		{
			_putchar(s[count]);
			count++;
		}

		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = convert(ptr, 16, 0, 1);

	return (count + 2);
}

/**
 * plus_func_num - plus flag
 * @list: pointer to list arguments
 * Return: length
 */
int plus_func_num(va_list list)
{
	int num = va_arg(list, int);

	if (num < 0)
	{
		num = print_number(num);
		return (num);
	}

	_putchar('+');
	num = print_number(num);

	return (num + 1);
}

/**
 * plus_func_ptr - plus flag
 * @list: pointer to list arguments
 * Return: length
 */
int plus_func_ptr(va_list list)
{
	int num = 0;

	_putchar('+');
	num = ptr_func(list);

	return (num + 1);
}

/**
 * width_func - handles field width
 * @list: pointer to list arguments
 * @width: width parameter received
 * @flag: check for minus flag
 * @match: check for match
 * @choice: array of structs previously declared
 * Return: value
 */
int width_func(va_list list, int width, int flag, char match, Choice choice[])
{
	int i = 0, count = 0, j;

	if (flag != 0)
	{
		for (; choice[i].specifier != NULL; i++)
		{
			if (match == choice[i].specifier[0])
			{
				count = choice[i].f(list);
				break;
			}
		}
		for (j = 0; j < width; j++)
		{
			_putchar(' ');
			count++;
		}
	}
	else
	{
		for (j = 0; j < width; j++)
		{
			_putchar(' ');
			count++;
		}
		for (i = 0; choice[i].specifier != NULL; i++)
		{
			if (match == choice[i].specifier[0])
			{
				int a = choice[i].f(list);

				count += a;
				break;
			}
		}
	}
	return (count);
}
/**
 * write_buffer - buffer to reduce write call
 * @buffer: buffer of size 1024
 * @count: count of words to be read from buffer
 */
void write_buffer(char buffer[], int count)
{
	int i = 0;

	for (; count > 0; i++, count--)
	{
		write(1, &buffer[i], 1);
	}
	i = 0;
}
