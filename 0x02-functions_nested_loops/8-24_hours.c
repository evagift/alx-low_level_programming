#include "main.h"
/**
 * jack_bauer - printing jacks minutes
 * Return: sucess
 */
void jack_bauer(void)
{
	int hr, minute;

	for (hr = 0; hr < 24; hr++)
	{
		for (minute = 0; minute < 60; minute++)
		{
		_putchar((hr / 10) + '0');
		_putchar((hr % 10) + '0');
		_putchar(':');
		_putchar((minute / 10) + '0');
		_putchar((minute % 10) + '0');
		_putchar('\n');
		}
	}
}
