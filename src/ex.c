#include "ftprintf.h"

void simple_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') 
    {
        if (*fmt == 'd') 
        {
            int i = va_arg(args, int);
            printf( "%d\n", i ) ;
        } 
        else if (*fmt == 'c') 
        {
            int c = va_arg(args, int);
            printf( "%c\n", (char)c ) ;
        } 
        else if (*fmt == 'f') 
        {
            double d = va_arg(args, double);
            printf( "%f\n", d ) ;
        }
        ++fmt;
    }

    va_end(args);
}