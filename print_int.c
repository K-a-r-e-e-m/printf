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
	int i, l;
	char digits[32];

	if (n < 0)
	{
		putchar('-'), (*len)++;
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		digits[i] = '0' + (n % 10);
		i++;
		(*len)++;
		n = n / 10;
	}
	for (l = (i - 1); l >= 0; l--)
	{
		putchar(digits[l]);
		(*len)++;
	}
	return (*len);
}
