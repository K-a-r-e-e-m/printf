#include "main.h"
/**
* format_char - prints characters
* @ap : the list of arugments
* Return: the number of characters printed
*/
int format_char(va_list ap)
{
	char a = va_arg(ap, int);

	putchar(a);
	return (1);
}
/**
* format_string - prints string
* @ap : the list of arugments
* Return: the number of characters of string printed
*/
int format_string(va_list ap)
{
	int i, len = 0;
	char *str = va_arg(ap, char*);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
		len++;
	}
	return (len);
}
/**
* rec_num - prints numbers
* @num : number to be printed
* Return: the length of number
*/
int rec_num(int num)
{
	int i = 0;

	if (num / 10)
		rec_num(num / 10);
	putchar(num % 10 + '0');
	i++;
	return (i);
}
/**
* format_numbers - prints numbers
* @ap : the list arugments
* Return: the numbers of the number printed
*/
int format_numbers(va_list ap)
{
	int len = 0;
	int i = va_arg(ap, int);

	if (i < 0)
	{
		putchar('-'), len++;
		i *= -1;
	}
	len = rec_num(i);
	return (len);
}
