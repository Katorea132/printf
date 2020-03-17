#include "holberton.h"
/**
 * _printf - Prints with formats to screen
 * @format: Holds such formats
 * @...: Many more arguments :D
 * Return: -1 on failure, number of printed chars on success
 */
int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int i, j, cnt = 0, flag, b = 1;
	frm form[] = {
		{"c", handc}, {"s", hands}, {"d", handi}, {"i", handi}, {"b", handb},
		{"S", handS}, {"r", handr}, {"R", handR}, {"x", handx}, {"X", handX},
		{"o", hando}, {"u", handu}, {"p", handp}, {0, 0}
	};

	if (format == 0)
		return (-1);
	va_start(arg, format);
	for (i = 0; format[i] != 0;)
	{	if (format[i] == '%' && format[i + b] == 0)
			return (-1);
		else if (format[i] == '%' && format[i + b] == ' ')
			b++;
		else  if (format[i] == '%' && format[i + b] == '%')
			_putchar('%'), i++, cnt += 1, b = 1;
		else if (format[i] == '%')
		{
			if (format[i + b] == 0)
				return (-1);
			for (j = 0, flag = 0; form[j].op != 0; j++)
				if (format[i + b] == form[j].op[0])
					cnt += form[j].p(arg), flag = 1, i += b + 1, b = 1;
			if (flag == 0)
				_putchar(format[i]), cnt += 1, i++;
		}
		else
			_putchar(format[i]), cnt += 1, i = i + b;
	}
	va_end(arg);
	return (cnt);
}
