#include "main.h"

/**
 * print_string - print string function.
 *
 * @str: The string passed to print it.
 * @len: The length of number.
 *
 * Description: This function prnit numbers.
 *
 * Return: The length of printed number.
 */
int print_string(char *str, int *len)
{
	int j;

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++, (*len)++)
		putchar(str[j]);

	return (*len);
}

/**
 * _printf - printf function.
 *
 * @format: The format is a list of types of arguments passed to the function.
 *
 * Description: This function produces output according to a format
 * by usnig variadic function (va_list, va_arg, va_end)
 * and access the next argument of the function by va_arg.
 *
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	va_list argValue; /* Arguments passed to list */
	int i = 0, len = 0;

	if (format == NULL || (format[0] == '%' && !format[1]) ||
	 (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1); /* Check if the given format fails return negative number */
	va_start(argValue, format); /* Start the list */
	while (format[i] != '\0')
	{	
		if (format[i] == '%')
		{
			i++; /* To skip the char after % and print the next */
			if (format[i] == 'c') /* Check the %c */
				putchar(va_arg(argValue, int)), len++;
			else if (format[i] == 's')/* Check the %s */
				print_string(va_arg(argValue, char *), &len);
			else if (format[i] == 'd'  || format[i] == 'i')/* Check the %d, %i */
				print_numbers(va_arg(argValue, int), &len);
			else if (format[i] == '%')/* Check the %% */
				putchar('%'), len++;
            else if (format[i] == 'b')
                print_binary(va_arg(argValue, int), &len);
			else/* If the given char after % unkown sprecifier */
				putchar('%'), putchar(format[i]), len += 2;
		}
		else
			putchar(format[i]), len++; /* If char not % print the char */
		i++;
	}
	va_end(argValue);
	return (len);
}
