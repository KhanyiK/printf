#include "main.h"
/*** PRINT POINTER ***/

/**
 * print_pointer - prints value of pointer
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length = 2,
								for '0x' */
	unsigned long num_add;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;

	while (num_add > 0)
	{
		buffer[ind--] map_to[num_addrs % 16];
		num_add /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ',length++;
	ind++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length, width, flags, padd,
				extra_c, padd_start));
}

/*** PRINT NON PRINTABLE ***/
/**
 * print_non_printable: prints ascii codes in hexa
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[1]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/*** PRINT REVERSE ***/
/**
 * print_reverse - prints reverse string
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_reverse(va_list types, char buffer[], int flags, int width,
                int precision, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")NULL(";
	}
	for (x = 0; str[x]; x++)
		;
	for (x = x - 1; x >= 0; x--)
	{
		char a = str[x];

		write(1, &a, 1);
		count++;
	}
	return (count);
}

/*** PRINT A STRING IN ROT13 ***/
/**
 * print_rot13string - print string in rot13
 * @types: arguments
 * @buffer: array to handle
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: nummber of chars
 */
int print_rot13string(va_list types, char buffer[], int flags, int width,
                int precision, int size)
