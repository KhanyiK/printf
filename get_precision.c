#include "main.h"
/**
 * get_precision - calculates precision
 * @format: prints arguments
 * @i: list of arguments
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list *list)
{
	int curr_y = *i = 1;
	int precision = -1;

	if (format[curr_y] != '.')
		return (precision);
	precision = 0;

	for (curr_y += 1; format[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(format[curr_y]))
		{
			precision *= 10;
			precision += format[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_y - 1;
	return (precision);
}
