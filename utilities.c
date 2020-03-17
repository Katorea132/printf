#include "holberton.h"
/**
 * _putchar - Puts a character on screeen
 * @c: Holds the character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * dectohex - Converts a decimal to hexadecimal
 * @d: Holds the decimal
 * @flag: Determines if upper case or not
 * Return: a pointer to an array of the hexa values
 */
char *dectohex(unsigned int d, int flag)
{
	char *s;
	unsigned int i, j, temp;

	for (i = 0, j = d; j != 0; i++, j /= 16)
		;
	s = malloc(sizeof(char) * (i + 1));
	if (s == 0)
		return (0);
	if (flag == 1)
	{
		for (i = 0; d != 0; i++, d /= 16)
		{
			temp = d % 16;
			if (temp < 10)
				s[i] = temp + '0';
			else
				s[i] = temp + 55;
		}
	}
	if (flag == 0)
	{
		for (i = 0; d != 0; i++, d /= 16)
		{
			temp = d % 16;
			if (temp < 10)
				s[i] = temp + '0';
			else
				s[i] = temp + 87;
		}
	}
	s[i] = 0;
	return (s);
}
/**
 * ultohex - Converts an unsigned long to hexadecimal
 * @d: Holds the decimal
 * @flag: Determines if upper case or not
 * Return: a pointer to an array of the hexa values
 */
char *ultohex(unsigned long int d, int flag)
{
	char *s;
	unsigned long int i, j, temp;

	for (i = 0, j = d; j != 0; i++, j /= 16)
		;
	s = malloc(sizeof(char) * (i + 1));
	if (s == 0)
		return (0);
	if (flag == 1)
	{
		for (i = 0; d != 0; i++, d /= 16)
		{
			temp = d % 16;
			if (temp < 10)
				s[i] = temp + '0';
			else
				s[i] = temp + 55;
		}
	}
	if (flag == 0)
	{
		for (i = 0; d != 0; i++, d /= 16)
		{
			temp = d % 16;
			if (temp < 10)
				s[i] = temp + '0';
			else
				s[i] = temp + 87;
		}
	}
	s[i] = 0;
	return (s);
}
