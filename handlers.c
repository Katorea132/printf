#include "holberton.h"
/**
 * handc - handles chars
 * @arg: Holds the arguments
 * @buffer: buffer of memory
 * @n: number of characters
 * Return: number of characters
 */
int handc(va_list arg, char *buffer, int n)
{
	buffer[n] = va_arg(arg, int);
	return (n + 1);
}
/**
 * hands - handles strings
 * @arg: Holds the arguments
 * @buffer: buffer of memory
 * @n: counter of characters
 * Return: number of characters
 */
int hands(va_list arg, char *buffer, int n)
{
	int i;
	char *s = va_arg(arg, char *);

	if (s == 0)
	{
		s = "(null)";
		for (i = 0; s[i] != 0; i++)
		{
			buffer[n] = s[i];
			n++;
		}
		return (n);
	}
	for (i = 0; s[i] != 0; i++)
	{
		buffer[n] = s[i];
		n++;
	}
	return (n);
}
/**
 * handi - handles integers
 * @arg: Holds the arguments
 * @buffer: buffer of memory
 * @n: number of characters
 * Return: number of characters
 */
int handi(va_list arg, char *buffer, int n)
{
	int num, i, j;
	unsigned int num2;
	int x = 1;

	num = va_arg(arg, int);

	if (num < 0)
	{
		num = -1 * num;
		buffer[n] = '-';
		n++;
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
		n;
	}
	return (n);
}
/**
 * handb - Handles binaries
 * @arg: Holds the argument
 * @buffer: buffer of memory
 * @n: number of characters
 * Return: Number of characters
 */
int handb(va_list arg, char *buffer, int n)
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
		resl[i] = (num % 2) + '0';
		num = num / 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[n] = resl[j];
		n++;
	}
	return (n);
}