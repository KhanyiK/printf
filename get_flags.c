#include "main.h"
/**
 * get_flags - calculates active flags
 * @format: prints arguments
 * @i: parameter
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # '' */
	/* 1 2 4 8 16 */
	int x, curr_y;
	const char FLAGS_ch[] = {'-', '+', '0', '#', '', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_y = *i + 1; format[curr_y] != '\0'; curr_y++)
	{
		for (x = 0; FLAGS_ch[x] != '\0'; x++)
			if (format[curr_y] == FLAGSCH[X])
			{
				flags |= FLAGS_ARR[x];
				break;
			}
		if (FLAGS_CH[x] == 0)
			break;
	}
	*i = curr_y - 1;
	return (flags);
}

