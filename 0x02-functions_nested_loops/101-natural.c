#include <stdio.h>
/**
 * main - Entry point
 * Description: 'computing the natural numbers'
 * Return: Always 0 (success)
 */
int main(void)
{
	int sum = 0, a;

	for (a = 1; a < 1024; a++)
	{
		if (a % 3 == 0 || a % 5 == 0)
		{
			sum += a;
		}
	}
	printf("%d\n", sum);
	return (0);
}
