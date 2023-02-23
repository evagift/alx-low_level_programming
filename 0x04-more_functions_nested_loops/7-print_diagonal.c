#include "main.h"
/**
 * print_diagonal - printing a diagonal line
 * @n: numbers of line to print
 * Return: Always Success
 */
void print_diagonal(int n)
{
	int a, b;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < a; b++)
		{
			_putchar(' ');
		}
	_putchar('\\');
	_putchar('\n');
	}
}
