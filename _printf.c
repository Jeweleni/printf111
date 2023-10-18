#include "main.h"
/*
 * _printf - function that produces output according to a format
 * @format: format string with a variable number of placeholders.
 *
 * Return: the number of characters printed.
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int num_of_char_printed = 0;
	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_of_char_printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
				num_of_char_printed++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				num_of_char_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char *);
				int len_of_str = 0;

				while (str[len_of_str] != '\0')
					len_of_str++;

				write(1, str, len_of_str);
				num_of_char_printed = num_of_char_printed + len_of_str;
			}
		}
		format++;
	}
	va_end(arg_list);
	return (num_of_char_printed);
}
