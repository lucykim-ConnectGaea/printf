#include <stdio.h>
#include <stdarg.h>
/**
*/

int printf(const char *format, ...)
{
    var_list argmts;/**va_list that stores function arg*/
    va_start(argmts, format);/**init argmts*/
    int chnum;/**number of characters in the function*/
    chnum = 0;
    char chrt;/**stores a single character value*/
    
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
                        char *string = va_arg(argmts, char *);
                        while (*string)
                            {
                                putchar(*string);
                            }
                            string++;
                            chnum++;
                            break;
                            
                            case '%':
                                putchar('%');
                                chnum++;
                                break;
            }
            else
            {
                putchar(*format);
                chnum++;
            }
            format++;
        }
        va_end(args);
        return (chnum);
    }
}   
}
