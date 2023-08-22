#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "string.h"
#include <stdlib.h>
int _printf(const char *format, ...);
int print_numbers(int n, int *len);
int print_binary(unsigned int number, int *length);
int print_unsign(unsigned int number, int *length);
int print_octal(unsigned int number, int *length);
int print_hexaSml(unsigned int number, int *length);
int print_hexaCap(unsigned int number, int *length);

#endif
