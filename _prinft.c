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
	unsigned int i, j, cnt = 0, flag = 0;
	char *buffer;
	frm form[] = {
		{"c", handc}, {"s", hands}, {"d", handi}, {"i", handi}, {"b", handb},
		{"S", handS}, {"r", handr}, {"R", handR}, {"x", handx}, {"X", handX},
		{"o", hando}, {"u", handu}, {"p", handp}, {"%", handv}, {0, 0}
	};
	va_start(arg, format);

	if (format == 0)
		return (-1);
	buffer = malloc(sizeof(char) * 5024);
	if (buffer == 0)
		return (-1);
	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 0)
				return (-1);
			i++;
			for (j = 0; form[j].op != 0; j++)
				if (form[j].op[0] == format[i])
					cnt = form[j].p(arg, buffer, cnt), flag = 1;
			if (flag == 0)
			{
				buffer[cnt] = format[i - 1];
				buffer[cnt + 1] = format[i];
				cnt += 2;
			}
		}
		else
			buffer[cnt] = format[i], cnt++;
		flag = 0;
	}
	write(1, buffer, cnt);
	va_end(arg);
	free(buffer);
	return (cnt);
}
