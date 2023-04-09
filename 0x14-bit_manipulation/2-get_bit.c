#include <stdio.h>
#include "main.h"
/**
 * get_bit - get the value of a bit
 * @index: index starting from 0, 
 * Return: Value of bit at index, 
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    return ((n >> index) & 1);
}

