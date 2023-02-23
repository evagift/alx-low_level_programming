#include "main.h"
/**
 * more_numbers - looping my numbers 10 times
 * Return: Always success
 */
void more_numbers(void)
{
	int a = 0;
	int b;

	while (a < 10)
	{
		b = 0;
		while (b < 15)
		{
			if (b > 9)
			{
				_putchar('0' + b / 10);
			}
			_putchar('0' + b % 10);
			b++;
		}
		_putchar('\n');
		a++;
	}
}

