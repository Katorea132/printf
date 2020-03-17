#include "holberton.h"
/**
 * handc - handles chars
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handc(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}
/**
 * hands - handles strings
 * @arg: Holds the arguments
 * Return: number of characters
 */
int hands(va_list arg)
{
	unsigned int i;
	char *s;

	s = va_arg(arg, char  *);
	if (s == 0)
		s = "(null)";
	for (i = 0; s[i] != 0; i++)
		_putchar(s[i]);
	return (i);
}
/**
 * handi - handles integers and doubles
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handi(va_list arg)
{
	int n, i, j, k, l = 1;
	unsigned int temp;

	i = 0;
	n = va_arg(arg, int);
	if (n < 0)
	{
		n = -1 * n;
		_putchar('-');
		i++;
	}
	temp = n;

	for (j = 0; n / 10 != 0; j++)
		n = n / 10;
	for (k = 0; k <= j - 1; k++)
		l = l * 10;
	for (; l != 0;)
	{
		_putchar((temp / l) + '0');
		temp = temp % l;
		l = l / 10;
		i++;
	}
	return (i);
}
/**
 * handb - Handles binaries
 * @arg: Holds the argument
 * Return: Number of characters
 */
int handb(va_list arg)
{
	unsigned int i = va_arg(arg, unsigned int);
	int j, b;
	int *array;

	if (i == 0)
	{
		_putchar('0');
		return (1);
	}
	for (j = 0, b = i; b != 0; j++, b /= 2)
		;
	array = malloc(j * sizeof(unsigned int));
	if (array == 0)
		return (0);
	for (b = j - 1; i > 0; i /= 2, j--)
		array[j] = i % 2;
	for (j = 0; j <= b; j++)
		_putchar(array[j + 1] + '0');
	free(array);
	return (b + 1);
}
