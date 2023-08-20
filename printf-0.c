#include "main.h"
/**
* print_numbers - prints out the numbers
* @num : the number to be printed
*/
void print_numbers(int num)
{
	if (num < 0)
	{
		putchar('-');
		print_numbers(-1 * num);
	}
	else
	{
		if (num / 10)
			print_numbers(num / 10);
		putchar((num % 10) + '0');
	}
}
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
	int i = 0, len = 0, j, n, car;
	char *str;

	if (format == NULL)
		return (-1);
	va_start(argValue, format); /* Start the list */
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++; /* To skip the char after % and print the next */
			if (format[i] == 'c') /* Check the %c */
			{/* Access the next argument of the function by va_arg */
				car = va_arg(argValue, int);
				putchar(car), len++;
			}
			else if (format[i] == 's')/* Check the %s */
			{
				str = va_arg(argValue, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++, len++)
					putchar(str[j]);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				n = va_arg(argValue, int);
				print_numbers(n);
			}
			else if (format[i] == '%')/* Check the %% */
				putchar('%'), len++;
			else
			{
				putchar('?');
				len++;
			}
		}
		else
			putchar(format[i]), len++; /* If char not % print the char */
		i++;
	}
	va_end(argValue);
	return (len);
}
