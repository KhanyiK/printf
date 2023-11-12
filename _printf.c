#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the printf function
 * @format: the format
 * Return: chars
 */
int _printf(const char *format, ...)
{
	int x, y = 0, chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/*write(1, &format[x], 1)*/
			chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
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
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (chars);
}
/**
 * print_buffer - prints buffer if it is there
 * @buffer: char array
 * @buff_ind: length of char
 */
void print_buffer(char buffer[], int *buff_ind);
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
