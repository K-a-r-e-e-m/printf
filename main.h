#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "string.h"
#include <stdlib.h>

int _printf(const char *format, ...);
int format_char(va_list ap);
int format_string(va_list ap);
int rec_num(int num);
int print_numbers(int n, int *len);
int print_binary(int number, int *length);

/**
* struct list - format printing
*
* @s : data type format
* @f : funcrion pointer
*/
typedef struct list
{

	char *s;
	int (*f)(va_list);
} List;
#endif
