#include "main.h"

void print_output(char output[], int *output_ind);

/**
 * _printf - Custom printf function that produces output
 * according to a format.
 * @format: format.
 * Return: Number of characters printed (excluding null byte),
 * or -1 if the format string is NULL.
 */
int _printf(const char *format, ...)
{
	int ind, char_print = 0, total_char = 0;
	int flags, width, precision, size, output_ind = 0;
	va_list arg_list;
	char output[OUTPUT_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (ind = 0; format && format[ind] != '\0'; ind++)
	{
		if (format[ind] != '%')
		{
			output[output_ind++] = format[ind];
			if (output_ind == OUTPUT_SIZE)
				print_output(output, &output_ind);
			/* write(1, &format[i], 1);*/
			total_char++;
		}
		else
		{
			print_output(output, &output_ind);
			flags = get_flags(format, &ind);
			width = get_width(format, &ind, arg_list);
			precision = get_precision(format, &ind, arg_list);
			size = get_size(format, &ind);
			++ind;
			char_print = handle_print(format, &ind, arg_list, output,
				flags, width, precision, size);
			if (char_print == -1)
				return (-1);
			total_char = total_char + char_print;
		}
	}

	print_output(output, &output_ind);

	va_end(arg_list);

	return (total_char);
}

/**
 * print_output - Prints all the exisiting contents of output
 * @output: An array of chars
 * @output_ind: Index at which to add next char, represents the length.
 */
void print_output(char output[], int *output_ind)
{
	if (*output_ind > 0)
		write(1, &output[0], *output_ind);

	*output_ind = 0;
}
