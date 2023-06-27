#include <stdio.h>
#include <stdarg.h>

/**
*/

int printf(const char *format, ...)
{
	int chnum;/**stores a single character value*/
	char chrt;
	char *str;

	va_list argmts;/**va_list that stores function arg*/
	va_start(argmts, format);/**init argmts*/
	
	chnum= 0;/**number of characters in the function*/
	while (*format)
	{
		if (*format == '%')
		{
			format++;/**advance after '%'*/
			switch (*format)
			{
				case 'c':
					chrt = (char)va_arg(argmts, int);
					putchar(chrt);
					chnum++;
					break;
				case 's':
					str = va_arg(argmts, char *);
					while (*str)
					{
						putchar(*str);
					}
					str++;
					chnum++;
					break;
				case '%':
					putchar('%');
					chnum++;
					break;
			}
		}
		else
			{
				putchar(*format);
				chnum++;
			}
			format++;
		}
		va_end(argmts);
		return(chnum);
}
