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
	char *s = NULL;
	unsigned int dec, temp;
	int i, j, h;
	char nu[7] = "(null)";
	char hex[20];

	s = va_arg(arg, char *);
	if (s == NULL)
	{
		for (i = 0; i < 6; i++)
			buffer[n++] = nu[i];
		return (n);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 0 && s[i] <= 31) || (s[i] >= 127))
		{
			buffer[n++] = '\\';
			buffer[n++] = 'x';
			dec = s[i] - 0;
			if (dec <= 15)
				buffer[n++] = '0';
			for (h = 0; dec != 0; h++)
			{
				temp = 0;
				temp = dec % 16;
				if (temp < 10)
					hex[h] = temp + 48;
				else
					hex[h] = temp + 55;
				dec = dec / 16;
			}
			for (j = h - 1; j >= 0; j--)
				buffer[n++] = hex[j];
		}
		else
			buffer[n++] = s[i];
	}
	return (n);
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
	int i, j;
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
	for (j = i - 1; j >= 0; j--)
	{
		buffer[n] = s[j];
		n++;
	}
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
