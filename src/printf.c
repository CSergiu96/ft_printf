#include "ftprintf.h"

/***********************************************\
|			   Function format					|
|												|
|  %[flags][width][.precision][length]specifier |
|												|
|-----------------------------------------------|
|				   Return           			|
|												|
|  The function returns the number of characters|
| that it printed, or a negative value if some 	|
| sort of error occurred.						|
|												|
\***********************************************/


int 	ft_printf(const char *format, ...)
{
	va_list args;
    va_start(args, format);
    
    return(print(format, args));
}