# 0x10. C - printf
## Sebastián Escobar Jimenez, Camilo Andrés Pulgarín
### _printf
A function that sends to stdout a formated string of characters. This function is based on GNU printf.

The syntax of the function is as follow:
**syntax:** `int _printf(const char *format, ...);

You need to install our holberton.h library in order to work with this function.

the format converters accepted are:

- **c** - character
- **s** - string
- **d** - decimal
- **i** - integer
- **%** - percentage sign
- **p** - memory addres
- **S** - Non printable characters are printed as "\x" followed by their ASCII values in a two digit hexadecimal number.
- **X, x** - Hexadecimal in uppercase (X) and lowercase(x).
- **o, b** - Ocatal(o) and binary(b)
- **r** - prints a reverse string
- **R** - ROT13

### Usage

_printf("%s, %s %d, %d\n", weekday, month, day, year);

**Output:**

`Monday, March 3, 2020`

compiled via:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c
```
# Authors

- Sebastián Escobar Jimenez. Github: https://github.com/Katorea132
- Camilo Andrés Pulgarín. Github: https://github.com/camilo620

Check out our other projects!