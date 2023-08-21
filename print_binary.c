#include "main.h"

/**
 * print_binary - print binary function.
 *
 * @number: The number passed to functoin to print it.
 * @length: The length of binary number.
 *
 * Description: This function convert the decimal number
 * to binary number and brint it.
 *
 * Return: The length of printed number.
 */
int print_binary(int number, int *length)
{
	int bnry[32]; /* The max number of bit that int number have */
	int idx = 0, j;

	if (number == 0) /* Check if the number is zero */
		putchar('0'), (*length)++;

	while (number != 0)
	{
		bnry[idx++] = number % 2;
		number /= 2;
	}

	/* (i - 1) --> start from the last indix before \0 */
	/* (= in >=) --> to check the first index 0 */
	for (j = (idx - 1); j >= 0; j--)
		putchar(bnry[j] + '0'), (*length)++;
	/* (+ '0') --> to convert number to charachter */

	return (*length);
}
