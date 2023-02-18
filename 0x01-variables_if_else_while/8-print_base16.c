#include <stdio.h>
/**
 * main - Entry point
 * Descritption: 'prints numbers od base 16 in lowercase'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char m;

	for (n = 0; n < 16; n++)
	{
		if (n < 10)
		{
			m = n + '0';
		}
		else
		{
			m = n - 10 + 'a';
		}
		putchar(m);
	}
	putchar('\n');
	return (0);
}
