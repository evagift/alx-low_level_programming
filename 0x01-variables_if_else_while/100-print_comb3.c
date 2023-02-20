#include <stdio.h>
/**
 * main - checking pointing
 * Description: 'print together from ten to hundred
 * Return: Always 0 (Success)
 */
int main(void)
{
	int 1 = 0;

	while (1 < 10)
	{
		int h = 1 + 1;

		while (h < 10)
		{
			putchar(1 + '0');
			putchar(h + '0');

			if (1 != 8 || h != 9)
			{
				putchar(',');
				putchar(' ');
			}
			h++;
		}
		1++;
	}
	putchar('\n');
	return (0);
}

