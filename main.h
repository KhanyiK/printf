#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZE*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: format
 * @fn: function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: formatt
 * @fm_t: function
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(va_list types, char buffer[], int flags, int width, int precision, int size);

/*** FUNCTIONS ***/
/* print chars and strings */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_dec(va_list args);
int print_bin(va_list args);
int print_37(void);
int print_oct(va_list args);
int print_HEX(va_list val);
int print_hex(va_list val);
int print_exc_string(va_list val);
int print_HEX_extra(unsigned int num);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* print numbers */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[], int flags, int width, int precision, int size);

/* print memory address */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* print non printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* handle other specifiers */
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i);

/* print string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* print a string in rot 13 */
int print_rot13stringi(va_list types, char buffer[], int flags, int width, int precision, int size);

#endif
