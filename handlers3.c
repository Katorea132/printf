#include "holberton.h"
int handS(va_list arg, char *buffer, int n)
{
    int i;
    char *s = va_arg(arg, char *);
    char *d;

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
		if ((s[i] >= 0 && s[i] < 32) || s[i] >= 127)
		{
			buffer[n] = ('\\');
            n++;
			buffer[n] = ('x');
            n++;
			if (s[i] == 0)
		    {
				buffer[n] = '0';
                n++;
                buffer[n] = '0';
                n++;
				return (n);
		    }
        d = dectohex(s[i], 1);
        if (d[1] == 0)
        {
				buffer[n] = '0';
                n++;
        }
        else
			buffer[n] = d[1];
            n++;
			buffer[n] = d[0];
            n++;
			free(d);
        }
		else
		_putchar(s[i]);
    }
	return (n);
}
