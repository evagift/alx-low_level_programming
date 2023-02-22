#include "main.h"
/**
 * _islower - Entry point
 * @c: checking id alps is lower case
 * Return: Always 0 9success)
 */
int _islower(int c)
{
	while (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}
