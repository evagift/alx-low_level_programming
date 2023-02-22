#include <stdio.h>
/**
 * main - Calculate the nth Fibonacci number recursively
 *
 * Return: The nth Fibonacci number
 */
int main(void)
{
	int i = 0;

	long a = 1;

	long b = 2;

	while (i < 50)
	{
		if (i == 0)
		{
			printf("%ld", a);
		}
		else if (i == 1)
		{
			printf(", %ld", b);
		}
		else
		{
			b += a;
			a = b - a;
			printf(", %ld", b);
		}
		++i;
	}
	printf("\n");
	return (0);
}
