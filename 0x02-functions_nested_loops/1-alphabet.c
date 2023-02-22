#include "main.h"
/**
 * print_alphabet - Checking point
 * Description: 'print alphs in lowercase'
 * Return: Always 0 (success)
 */
void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
