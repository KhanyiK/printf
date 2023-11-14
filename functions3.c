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
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length = 2, for '0x' */
	unsigned long num_adders;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
