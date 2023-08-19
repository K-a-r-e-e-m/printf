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
	int i = 0, len = 0, j;
	char *str;
	char car;

	va_start(argValue, format); /* Start the list */
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c') /* Check the %c */
			{/* Access the next argument of the function by va_arg */
				car = va_arg(argValue, int);
				putchar(car), len++;
			}
			else if (format[i + 1] == 's')/* Check the %s */
			{
				str = va_arg(argValue, char *);
				for (j = 0; str[j] != '\0'; j++, len++)
					putchar(str[j]);
			}
			else if (format[i + 1] == '%')/* Check the %% */
			{
				car = va_arg(argValue, int);
				putchar('%'), len++;
			}
			i++; /* To skip the char after % and print the next */
		}
		else
			putchar(format[i]), len++; /* If char not % print the char */
		i++;
	}
	va_end(argValue);
	return (len);
}
