#include <stdio.h>
/**
 * main - checking pointing
 * Description: 'print together from ten to hundred
 * Return: Always 0 (Success)
 */
int main(void)
{
	int l = 0;

	while (l < 10)
	{
		int h = l + 1;

		while (h < 10)
		{
			putchar(l + '0');
			putchar(h + '0');

			if (l != 8 || h != 9)
			{
				putchar(',');
				putchar(' ');
			}
			h++;
		}
		l++;
	}
	putchar('\n');
	return (0);
}

