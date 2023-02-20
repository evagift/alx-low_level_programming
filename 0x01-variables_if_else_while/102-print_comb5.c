#include <stdio.h>
/**
 * main - checking point
 * Description: 'combination of two digita'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a = 0;

	int b = 1;

	while (a < 100)
	{
		while (b < 100)
		{
			if (a != 0 || b != 1)
			{
				putchar(',');
				putchar(' ');
			}
			putchar(a / 10 + '0');
			putchar(b % 10 + '0');
			putchar(' ');
			putchar(b / 10 + '0');
			putchar(b % 10 + '0');
			b++
		}
		a++
			b = a + 1;
	}
	putchar('\n');
			return (0);
i}
