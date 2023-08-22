#include "main.h"
/**
 * print_unsign - print unsigned function.
 *
 * @number: The number passed to functoin to print it.
 * @length: The length of unsgined number.
 *
 * Description: This function print the unsigned int number.
 *
 * Return: The length of printed number.
 */
int print_unsign(unsigned int number, int *length)
{
	if (number / 10)/* call the function bu recursion */
		print_unsign(number / 10, length);
	/* print the number from last to first */
	putchar(number % 10 + '0'), (*length)++;

	return (*length);
}


/**
 * print_octal - print octal function.
 *
 * @number: The number passed to functoin to print it.
 * @length: The length of octal number.
 *
 * Description: This function convert the decimal argument
 * number to octal number and brint it.
 *
 * Return: The length of printed number.
 */
int print_octal(unsigned int number, int *length)
{
	unsigned int oct[64]; /* 64 bits to store the all the element */
	int idx = 0, j;      /* that max number in hexa can be */

	if (number == 0)
		putchar('0'), (*length)++;

	while (number != 0)
	{
		oct[idx++] = number % 8;
		number /= 8; /* devide number by 8 base of octal */
	}

	for (j = (idx - 1); j >= 0; j--) /* Print the result */
		putchar(oct[j] + '0'), (*length)++;

	return (*length);
}


/**
 * print_hexaSml - print hexa function.
 *
 * @number: The number passed to functoin to print it.
 * @length: The length of hexadecimal number.
 *
 * Description: This function convert the decimal argument
 * number to hexadecimal small and brint it.
 *
 * Return: The length of printed number.
 */
int print_hexaSml(unsigned int number, int *length)
{

	char hexSml[64]; /* 64 bits to store the all the element */
	int idx = 0, j, mod;

	if (number == 0)
		putchar('0'), (*length)++;

	while (number != 0)
	{
		mod = number % 16;

		if (mod >= 0 && mod <= 9)      /* add 48 to convert to number */
			hexSml[idx++] = mod + 48; /* char from 0 to 9 */

		else /* if number is 10 --> (10 + 87 = 97) --> a */
			hexSml[idx++] = mod + 87; /* char from a to f */

		number /= 16; /* devide number by 16 base of hexa */
	}

	for (j = (idx - 1); j >= 0; j--) /* Print the result */
		putchar(hexSml[j]), (*length)++;

	return (*length);
}


/**
 * print_hexaCap - print hexa function.
 *
 * @number: The number passed to functoin to convert it to hexa.
 * @length: The length of hexadecimal number.
 *
 * Description: This function convert the decimal argument
 * number to hexadecimal capital and brint it.
 *
 * Return: The length of printed number.
 */
int print_hexaCap(unsigned int number, int *length)
{
	char hexCap[64]; /* 64 bits to store the all the element in hex */
	int idx = 0, j, mod;

	if (number == 0)
		putchar('0'), (*length)++;

	while (number != 0)
	{
		mod = number % 16;

		if (mod >= 0 && mod <= 9)     /* add 48 to convert to number */
			hexCap[idx++] = mod + 48; /* char from 0 to 9 */

		else /* if number is 10 --> (10 + 55 = 65) --> A */
			hexCap[idx++] = mod + 55; /* char from A to F */

		number /= 16; /* devide number by 16 base of hexa */
	}

	for (j = (idx - 1); j >= 0; j--) /* Print the result */
		putchar(hexCap[j]), (*length)++;

	return (*length);
}
