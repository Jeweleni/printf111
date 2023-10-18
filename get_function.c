#include "main.h"

int _loopExtraction(Choice choice[], const char *format, int size,
					int *i,
					va_list list, int *count);
/**
 * nextFunction - next function
 * @current: current format
 * @check: choice to check against
 * @i: param i
 * @list: struct
 *
 * Return: loop return
 */
LoopReturn nextFuncton(const char *current, Choice check, int i, va_list list)
{
	LoopReturn lt;

	if (current[i + 2] == check.specifier[1] && check.specifier[0] == '+')
	{
		lt.count = check.f(list);
	}
	lt.i = i + 2;
	return (lt);
}

/**
 * get_function - gets needed function
 * @format: string
 * @list: variadic list
 * @choice: variadic struct
 * @size: size of struct
 *
 * Return: size of formatted string
 */
int get_function(const char *format, va_list list, Choice choice[], int size)
{
	int i = 0, count = 0;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			int a = _loopExtraction(choice, format, size, &i, list, &count);

			if (a < 0)
				return (-1);
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}

/**
 * _loopExtraction -  extracts loop
 * @choice: choice arr
 * @format: format str
 * @size: size of format str
 * @i: iterator
 * @list: variadic list
 * @count: str count
 *
 * Return: -1 if unsuccessful
 */
int _loopExtraction(Choice choice[], const char *format, int size, int *i,
					va_list list, int *count)
{
	int j = 0, num = 0;

	for (j = 0; j < size; j++)
	{
		if (choice[j].specifier)
		{
			if (format[*i + 1] == choice[j].specifier[0] && !choice[j].specifier[1])
			{
				num = choice[j].f(list);
				*count += num;
				*i += 1;
				break;
			}
		}
		if (format[*i + 1] == '+' && (format[*i + 2] == choice[j].specifier[1]))
		{
			num = choice[j].f(list);
			*count += num;
			*i += 2;
			break;
		}
		if (choice[j].specifier == NULL && format[*i + 1] != ' ')
		{
			if (format[*i + 1] != 0)
			{
				_putchar(format[*i]);
				_putchar(format[*i + 1]);
				*count += 2;
				*i += 1;
			}
			else
				return (-1);
		}
	}
	return (0);
}
