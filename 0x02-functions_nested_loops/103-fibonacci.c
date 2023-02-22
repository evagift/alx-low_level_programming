#include <stdio.h>
/**
 * main - print the sum of even fibonacci numbers
 * Return: success
 */
int main(void)
{
	int a = 0;

	long b = 1;

	long c = 2;

	long sum = c;

	while (c + b < 4000000)
	{
		c += b;
		if (c % 2 == 0)
			sum += c;
		b = c - b;
		++a;
	}
	printf("%ld\n", sum);
	return (0);
}
