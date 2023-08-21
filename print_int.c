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
	unsigned int num = n;

	if (n < 0)
	{
		putchar('-'), (*len)++;
		num *= -1;
	}
	if (num / 10)
	{
		print_numbers(num / 10, len);

	}
	putchar(num % 10 + '0'), (*len)++;
	return (*len);
}
