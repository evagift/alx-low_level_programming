#include "main.h"
/**
 * print_line - printing in
 * @n: the number of line to be drawn
 * Return: Always success
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	while (n > 0)
	{
		_putchar('_');
		n--;
	}
	_putchar('\n');
}
