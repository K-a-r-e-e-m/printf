#include "main.h"

/**
 * _printf - printf function.
 *
 * @format: The format is a list of types of arguments passed to the function.
 *
 * Description: This function produces output according to a format.
 *
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	va_list argValue; /* Arguments passed to list */
	int len = 0, j;
	char *str;
	char c;

	if (!format)
		return (-1);
	va_start(argValue, format); /* Start the list */
	while (format[i] != '\0' && format != NULL)
	{
		if (*format == '%')
		{
			format++; /* To skip the char after % and print the next */
			if (*format == 'c') /* Check the %c */
			{/* Access the next argument of the function by va_arg */
				car = va_arg(argValue, int);
				putchar(car), len++;
			}
			else if (*format == 's')/* Check the %s */
			{
				str = va_arg(argValue, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++, len++)
					putchar(str[j]);
			}
			else if (*format == '%')/* Check the %% */
				putchar(*format), len++;
		}
		else
		{
			putchar(*format), len++;/* If char not % print the char */
		}
			format++;
	}
	va_end(argValue);
	return (len);
}
