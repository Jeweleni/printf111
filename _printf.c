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
=======

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;

}
