#include <stdio.h>
/**
 * main - Entry point
 * Description: 'prints all possible digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 0;

	while (number < 10)
	{
		putchar(number + '0');
		{
			if (number < 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
		number++;
	}
	putchar('\n');
	return (0);
}
