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
 * handd - handles doubles
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handd(va_list arg)
{
	int n = va_arg(arg, int);
	int num, dig, exp = 1, i = 1;
	int last = n % 10;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num *= -1, n *= -1, last *= -1;
		i++;
	}
	if (num > 0)
	{
		for (; num / 10; num /= 10)
			exp *= 10;
		num = n;
		for (; exp > 0; exp /= 10, i++)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num -= (dig * exp);
		}
	}
	_putchar(last + '0');
	return (i);
}
/**
 * handi - handles integers
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handi(va_list arg)
{
	int n = va_arg(arg, int), num, last = n % 10;
	int dig, exp = 1, i = 1;

	n /= 10;
	num = n;
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		for (; num / 10 != 0; num /= 10)
			exp *= 10;
		num = n;
		for (; exp > 0; exp /= 10, i++)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
		}
	}
	_putchar(last + '0');
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

	for (j = 0, b = i; b > 0; j++, b /= 2)
		;
	array = malloc(j * sizeof(int));
	if (array == 0)
		return (0);
	for (b = j - 1; i > 0; i /= 2, j--)
		array[j] = i % 2;
	for (j = 0; j <= b; j++)
		_putchar(array[j + 1] + '0');
	free(array);
	return (b + 1);
}