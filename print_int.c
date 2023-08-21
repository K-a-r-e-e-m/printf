#include "main.h"
/**
 * print_numbers - print number function.
 *
 * @n: The number passed to print it.
 *
 * @len: The length of number.
 *
 * Description: This function prnit decimal numbers.
 *
 * Return: The length of printed number.
 */
int print_numbers(int n, int *len)
{
	unsigned int d = n; /* handles the no. between MIN and MAX of the int */

	if (n < 0) /* Checks if the no. is negative */
	{
		putchar('-'), (*len)++; /* printing out the '-' sign */
		d *= -1;
	}
	if (d / 10) /* Checking if the number is bigger than 10 */
	{
		print_numbers(d / 10, len); /* using recursive function */

	}
	putchar(d % 10 + '0'), (*len)++; /* printing the no. first digit */
	return (*len); /* return the numbers of the no. digits */
}
