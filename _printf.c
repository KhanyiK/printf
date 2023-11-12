#include "main.h"
/**
 * _printf - the printf function
 * @format: the format
 * Return: chars
 */
int _printf(const char *format, ...)
{
	int x, y = 0, chars = 0;
	int flags, width, precision, size, buff = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff++] = format[x];
			if (buff == BUFF_SIZE)
				print_buffer(buffer, &buff);
			/*write(1, &format[x], 1)*/
			chars++;
		}
		else
		{
			print_buffer(buffer, &buff);
			flags = get_flags(format, &x);
			width = get width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			y = handle_print(format, &x, list, buffer, flags, width, precision, size);

			if (y == -1)
				return (-1);
			chars += y;
		}
	}
	print_buffer(buffer, &buff);
	va_end(list);
	return (chars);
}
