#ifndef HOL
#define HOL
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * struct formats - Struct for formatss
 * @op: The format
 * @p: The hander function
 */
typedef struct formats
{
	char *op;
	int (*p)(va_list, char *, int);
} frm;
int _printf(const char *format, ...);
int _putchar(char c);
char *dectohex(unsigned int d, int flag);
char *ultohex(unsigned long int d, int flag);
int handc(va_list arg, char *, int);
int hands(va_list arg, char *, int);
int handi(va_list arg, char *, int);
int handb(va_list arg, char *, int);
int handS(va_list arg, char *, int);
int handr(va_list arg, char *, int);
int handR(va_list arg, char *, int);
int handx(va_list arg, char *, int);
int handX(va_list arg, char *, int);
int hando(va_list arg, char *, int);
int handu(va_list arg, char *, int);
int handp(va_list arg, char *, int);
int handv(va_list arg, char *, int);
#endif
