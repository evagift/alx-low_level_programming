#include <stdio.h>
/**
 * main - a program that prints the size of various computer sizes
 * Return: 0 (Success)
 */
int main(void)
{
	char a;
	int s;
	long int d;
	long long int f;
	float g;
printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(s));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(d));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(f));
printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(g));
return (0);
}
