#include "main.h"
/**
 * print_times_table - print 100 times table
 * @n: print the time table if n > 15
 * Return: Always 0 (success)
 */
void print_times_table(int n)
{
	int a, b;

	if (n < 0 || n > 15)
		return;
	for (a = 0; a <= n; a++)
	{
		for (b = 0; b <= n; b++)
		{
			int result = a * b;

			if (b == 0)
			{
				_putchar(result + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (result < 10)
				{
				_putchar(' ');
				_putchar(' ');
				_putchar(result + '0');
				}
				else if (result < 100)
				{
					_putchar(' ');
					_putchar(result / 10 + '0');
					_putchar(result % 10 + '0');
				}
				else
				{
					_putchar(result / 100 + '0');
					_putchar((result % 100) / 10 + '0');
					_putchar(result % 10 + '0');
				}
			}
		}
		_putchar('\n');
	}
}
