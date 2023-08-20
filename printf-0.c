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
	int i = 0, len = strlen(format), j;
	List sep[] = {
		{"c", format_char},
		{"s", format_string},
		{"d", format_numbers},
		{"i", format_numbers},
		{NULL, NULL}
		};
		va_list argValue; /* Arguments passed to list */
	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(argValue, format); /* Start the list */
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len--;
			i++;
			j = 0;
			while (sep[j].s)
			{
				if (format[i] == sep[j].s[0])
				{
					len = len + sep[j].f(argValue);
				}
				j++;
			}
			if (format[i] == '%')
			{
				putchar('%');
			}
		}
		else
			putchar(format[i]);
		i++;
	}
	va_end(argValue);
	return (len);
}
