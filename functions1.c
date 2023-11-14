#include "main.h"
/*** PRINT CHAR ***/

/**
 * print_char - prints a char
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char x = va_arg(types, int);

	return (handle_write_char(x, buffer, flags, width,
				precision, size));
}

/*** PRINT A STRING ***/
/**
 * print_string - prints string
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of chars
 */
int print_string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int length = 0, y;
	chaar *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precion);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (y = width - length; y > 0; y--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (y = width - length; y > 0; y--)
				write(1, "", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/*** PRINT PERCENT SIGN ***/
/**
 * print_percent - prints percent sign
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/*** PRINT INT ***/
/**
 * print_int - prints int
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int c = va_arg(types, long int);
	unsigned long int num;

	c = convert_size_number(c, size);

	if (c == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)c;

	if (c < 0)
	{
		num = (unsigned long int)((-1) * c);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}
	x++;
	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}
/*** PRINT BINARY ***/
/**
 * print_binary - prints unsigned number
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int x, y, r, s;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;/*(2^31)*/
	a[0] = x / y;

	for (i = 1; i < 32; i++)
	{
		y /= 2;
		a[r] = (x / y) % 2;
	}
	for (r = 0, s = 0, count = 0; r < 32; r++)
	{
		s += a[r];
		if (s || r == 31)
		{
			char c = '0' + a[r];

			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
