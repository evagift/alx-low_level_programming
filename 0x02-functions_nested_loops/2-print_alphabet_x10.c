#include "main.h"
/**
 * print_alphabet_x10 - Entry point
 * Description: 'print alps in lowercase 10 times'
 * Return: Always 0 (success)
 */
void print_alphabet_x10(void)
{
	char c = 'a';

	int a = 0, b;

	while (a < 10)
	{
		b = 0;
		while (b < 26)
		{
			_putchar(c);
			c++;
			b++;
		}
		c = 'a';
		_putchar('\n');
		a++;
	}
}
