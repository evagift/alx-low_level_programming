#include <stdio.h>
/**
 * main - Entry point
 * Description: 'prints a-z alph but ommits e and q'
 * Return: Always 0 (Success)
 */
int main(void)
{
	char d;

	for (d = 'a'; d <= 'z'; ++d)
	{
	if (d != 'e' && d != 'q')
	{
	putchar(d);
	}
	}
	putchar('\n');
	return (0);
}
