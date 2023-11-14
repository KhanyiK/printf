#include "main.h"

/*** PRINT UNSIGNED NUMBER ***/
/**
 * print_unsigned - prints unsigned number
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/*** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - prints unsigned number in octal
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_sizeu_nsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 8) + '0';
		num / 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[x--] = '0';
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/*** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***/
/**
 * print_hexadecimal - prints unsigned number in hexadecimal
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width,
				precision, size));
}

/*** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - prints unsigned number in hexadecimal upper
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',
				width, precision, size));
}

/*** PRINT HEXX NUMBER IN LOWER OR UPPER ***/
/**
 * print_hexa - prints hexadecimal number in lower or upper
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_hexa(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to(num % 16) + '0';
		num / 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
