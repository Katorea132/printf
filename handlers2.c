#include "holberton.h"
/**
 * hando - Handles octals
 * @arg: Holds the argument
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: Number of characters
 */
int hando(va_list arg, char *buffer, int n)
{
	unsigned int i = va_arg(arg, unsigned int);
	unsigned int j, b;
	unsigned int *array;

	buffer[n] = '0';

	if (i == 0)
	{
		_putchar('0');
		return (1);
	}
	for (j = 0, b = i; b > 0; j++, b /= 8)
		;
	array = malloc(j * sizeof(unsigned int));
	if (array == 0)
		return (0);
	for (b = j - 1; i > 0; i /= 8, j--)
		array[j] = i % 8;
	for (j = 0; j <= b; j++)
		_putchar(array[j + 1] + '0');
	free(array);
	return (b + 1);
}
/**
 * handu - handles unsigneds
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @d: Holds the counter
 * Return: number of characters
 */
int handu(va_list arg, char *buffer, int d)
{
	unsigned int n = va_arg(arg, int), num, last = n % 10;
	unsigned int dig, exp = 1, i = 1;

	buffer[d] = '0';

	n /= 10;
	num = n;
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
 * handp - handles hexadecimal in upper case
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handp(va_list arg, char *buffer, int n)
{
	unsigned long int d = va_arg(arg, unsigned long);
	int i, tmp;
	char *s;

	buffer[n] = '0';

	if (d == 0)
	{
		_putchar('0');
		_putchar('x');
		_putchar('0');
		return (3);
	}
	s = ultohex(d, 0);
	for (i = 0; s[i] != 0; i++)
		;
	_putchar('0');
	_putchar('x');
	for (tmp = i; tmp >= 0; tmp--)
		_putchar(s[tmp - 1]);
	free(s);
	return (i + 2);
}
/**
 * handv - handles percentage
 * @arg: Holds the arguments
 * @b: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handv(va_list arg __attribute__((__unused__)), char *b, int n)
{
	b[n] = '%';
	return (n + 1);
}
