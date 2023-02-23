#include "main.h"
/**
 * _isdigit - checking if value is digit
 * @c: value to be checked
 * Return: always success
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
