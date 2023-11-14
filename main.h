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
#endif
