#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0
 * if there is one or more chars in the string
 * b that is not 0 or 1 or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int total, lada;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (lada = 1, total = 0, len--; len >= 0; len--, lada *= 2)
	{
		if (b[len] == '1')
			total += lada;
	}

	return (total);
}
