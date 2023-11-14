#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
 * typedef struct fmt fmt_t - struct op
 * @fmt: formatt
 * @fm_t: function
 */
tpedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(va_list types, char buffer[], int flags, int width, int precision, int size);

/*** FUNCTIONS ***/
/*functions to print chars and strings*/
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
int _printf(const char *format, ...);
int _strlen(const char *str);
int strlen(char *str);
int print_dec(va_list args);
int print_bin(va_list args);
int print_unsigned(va_list args);
int print_37(void);
int print_int(va_list args);
int print_oct(va_list args);
int print_HEX(va_list val);
int print_hex(va_list val);
int print_exc_string(va_list val);
int print_HEX_extra(unsigned int num);
#endif
