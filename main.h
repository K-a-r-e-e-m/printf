#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "string.h"
#include <stdlib.h>

int _printf(const char *format, ...);
int print_numbers(int n, int *len);
<<<<<<< HEAD
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
=======
>>>>>>> ede08e65f8868c3958be1a0bb52b62c77855bbf0
#endif
