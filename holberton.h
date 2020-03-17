#ifndef HOL
#define HOL
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct formats - Struct for formats
 * @op: The format
 * @p: The function
 */
typedef struct formats
{
	char *op;
	int (*p)();
} frm;
int _printf(const char *format, ...);
int _putchar(char c);
char *dectohex(unsigned int d, int flag);
char *ultohex(unsigned long int d, int flag);
int handc(va_list arg);
int hands(va_list arg);
int handd(va_list arg);
int handi(va_list arg);
int handb(va_list arg);
int handS(va_list arg);
int handr(va_list arg);
int handR(va_list arg);
int handx(va_list arg);
int handX(va_list arg);
int hando(va_list arg);
int handu(va_list arg);
int handp(va_list arg);
#endif