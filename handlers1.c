#include "holberton.h"
/**
 * handS - handles strings with special characters
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handS(va_list arg)
{
	unsigned int i, b = 0;
	char *s, *d;

	s = va_arg(arg, char  *);
	if (s == 0)
		s = "(null)";
	for (i = 0; s[i] != 0; i++)
	{
		if ((s[i] >= 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
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
 * Return: number of characters
 */
int handr(va_list arg)
{
	unsigned int i, b;
	char *s;

	s = va_arg(arg, char  *);
	if (s == 0)
		s = "(null)";
	for (i = 0; s[i] != 0; i++)
		;
	for (b = i; b >= 1; b--)
		_putchar(s[b - 1]);
	return (i);
}
/**
 * handR - handles rot13 encription.
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handR(va_list arg)
{
	unsigned int itmp, i, j, k = 0;
	char *s;
	char d[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char e[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";
	char *tmp;

	s = va_arg(arg, char  *);
	if (s == 0)
		s = "(null)";
	for (itmp = 0; s[itmp] != 0; itmp++)
		;
	tmp = malloc(sizeof(char) * itmp);
	for (i = 0; s[i] != 0; i++)
	{
		tmp[i] = s[i];
		for (j = 0; d[j]; j++)
		{
			if (tmp[i] == d[j])
			{
				k = j;
				tmp[i] = e[k];
				break;
			}
		}
		_putchar(tmp[i]);
	}
	free(tmp);
	return (i);
}
/**
 * handx - handles hexadecimal in lower case
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handx(va_list arg)
{
	unsigned int d = va_arg(arg, unsigned int);
	int i, tmp;
	char *s;

	s = dectohex(d, 0);
	for (i = 0; s[i] != 0; i++)
		;
	for (tmp = i; tmp >= 0; tmp--)
		_putchar(s[tmp - 1]);
	free(s);
	return (i);
}
/**
 * handX - handles hexadecimal in upper case
 * @arg: Holds the arguments
 * Return: number of characters
 */
int handX(va_list arg)
{
	unsigned int d = va_arg(arg, unsigned int);
	int i, tmp;
	char *s;

	s = dectohex(d, 1);
	for (i = 0; s[i] != 0; i++)
		;
	for (tmp = i; tmp >= 0; tmp--)
		_putchar(s[tmp - 1]);
	free(s);
	return (i);
}