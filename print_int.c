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
