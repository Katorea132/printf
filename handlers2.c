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
	unsigned int num = va_arg(arg, unsigned int);
	int i, j;
	char resl[300];

	if (num == 0)
	{
		buffer[n] = '0';
		return (n + 1);
	}

	for (i = 0; num != 0; i++)
	{
		resl[i] = (num % 8) + '0';
		num = num / 8;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[n] = resl[j];
		n++;
	}
	return (n);
}
/**
 * handu - handles unsigneds
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handu(va_list arg, char *buffer, int n)
{
	unsigned int num, i, j;
	unsigned int num2;
	unsigned int x = 1;

	num = va_arg(arg, int);

	if (num == 0)
	{
		buffer[n] = '0';
		return (n + 1);
	}


	num2 = num;
	for (i = 0; num / 10 != 0; i++)
	{
		num = num / 10;
	}
	for (j = 0; j <= i - 1; j++)
	{
		x = x * 10;
	}

	for (; x != 0;)
	{
		buffer[n] = (num2 / x) + '0';
		num2 = num2 % x;
		x = x / 10;
		n++;
	}
	return (n);
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
	long int i, j, tmp;
	char s[200];
	char x[] = "0x";
	char y[] = "(nil)";

	if (d == 0)
	{
		for (i = 0; y[i] != 0; i++)
		{
			buffer[n] = y[i];
			n++;
		}
		return (n);
	}
	for (i = 0; x[i] != 0; i++)
	{
		buffer[n] = x[i];
		n++;
	}
	for (i = 0, tmp = 0; d != 0; i++)
	{
		tmp = d % 16;
		if (tmp < 10)
			s[i] = tmp + 48;
		else
			s[i] = tmp + 87;
		d /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[n] = s[j];
		n++;
	}
	return (n);
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
