#include "main.h"
/**
 * print_numbers - loopinf number from base 0
 * Return: Always success
 */
void print_numbers(void)
{
	int c = 0;

	while (c < 10)
	{
		_putchar(c + '0');
		c++;
	}
	_putchar('\n');
}
