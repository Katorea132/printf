#include "holberton.h"
/**
 * handS - handles strings with special characters
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handS(va_list arg, char *buffer, int n)
{
	unsigned int i, b = 0;
	char *s, *d;

	s = va_arg(arg, char  *);
	if (s == 0)
		return (0);
	for (i = 0; s[i] != 0; i++)
	{
		if ((s[i] >= 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (d == 0)
			{
				_putchar('0');
				_putchar('0');
				return (4);
			}
			d = dectohex(s[i], 1);
			if (d[1] == 0)
				_putchar('0');
			else
				_putchar(d[1]);
			_putchar(d[0]);
			free(d);
			b += 2;
		}
		else
			_putchar(s[i]);
	}
	b += i;
	return (b);
}
/**
 * handr - handles strings
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the actual counter
 * Return: number of characters
 */
int handr(va_list arg, char *buffer, int n)
{
	unsigned int i, j;
	char *s;
	char nu[7] = "(null)";

	s = va_arg(arg, char  *);
	if (s == 0)
	{
		for (i = 0; i < 6; i++, n++)
			buffer[n] = nu[i];
		return (n);
	}
	for (i = 0; s[i] != 0; i++)
		;
	for (j = i - 1; j >= 0; j--, n++)
		buffer[n] = s[j];
	return (n);
}
/**
 * handR - handles rot13 encription.
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the actual counter
 * Return: number of characters
 */
int handR(va_list arg, char *buffer, int n)
{
	unsigned int i, j;
	char *s;
	char d[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char e[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	s = va_arg(arg, char  *);
	for (i = 0; s[i] != 0; i++)
	{
		for (j = 0; d[j] != 0; j++)
			if (d[j] == s[i])
			{
				buffer[n] = e[j];
				n++;
				break;
			}
		if (d[j] != s[i])
		{
			buffer[n] = s[i];
			n++;
		}
	}
	return (n);
}
/**
 * handx - handles hexadecimal in lower case
 * @arg: Holds the arguments
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handx(va_list arg, char *buffer, int n)
{
	unsigned int d = va_arg(arg, unsigned int);
	int i, j, tmp;
	char s[200];

	if (d == 0)
	{
		buffer[n] = '0';
		return (n + 1);
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
 * handX - handles hexadecimal in upper case
 * @arg: Holds the argument
 * @buffer: Holds the buffer
 * @n: Holds the counter
 * Return: number of characters
 */
int handX(va_list arg, char *buffer, int n)
{
	unsigned int d = va_arg(arg, unsigned int);
	int i, j, tmp;
	char s[200];

	if (d == 0)
	{
		buffer[n] = '0';
		return (n + 1);
	}
	for (i = 0, tmp = 0; d != 0; i++)
	{
		tmp = d % 16;
		if (tmp < 10)
			s[i] = tmp + 48;
		else
			s[i] = tmp + 55;
		d /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[n] = s[j];
		n++;
	}
	return (n);
}
