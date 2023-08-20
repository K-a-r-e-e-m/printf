#include "main.h"

/**
 * print_numbers - print number function.
 *
 * @n: The number passed to print it.
 * @len: The length of number.
 *
 * Description: This function prnit numbers.
 *
 * Return: The length of printed number.
 */
int print_numbers(int n, int *len)
{
	if (n < 0)
	{
		putchar('-'), (*len)++;
		n *= -1;
	}
	if (n / 10)
	{
		print_numbers(n / 10, len);

	}
	putchar(n % 10 + '0'), (*len)++;
	return (*len);
}

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
 * Description: This function produces output according to a format.
 *
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	va_list argValue; /* Arguments passed to list */
	int i = 0, len = 0, n, car;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
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
				print_string(va_arg(argValue, char *), &len);

			else if (format[i] == 'd' || format[i] == 'i')
			{
				n = va_arg(argValue, int);
				print_numbers(n, &len);
			}
			else if (format[i] == '%')/* Check the %% */
				putchar('%'), len++;
		}
		else
			putchar(format[i]), len++; /* If char not % print the char */
		i++;
	}
	va_end(argValue);
	return (len);
}
