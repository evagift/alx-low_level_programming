#include "main.h"
/**
 * print_last_digit - printing last digit.
 * @n: the value to be printed
 * Return: return 0 if success
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
	{
		last_digit = last_digit * -1;
	}
	_putchar(last_digit + '0');
	return (last_digit);
}
