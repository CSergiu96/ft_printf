#include "ftprintf.h"


/***********************************************\
|			   Function format					|
|												|
|  %[flags][width][.precision][length]specifier |
|-----------------------------------------------|
|				   Return           			|
|												|
|  The function returns the number of characters|
| that it printed, or a negative value if some 	|
| sort of error occurred.						|
\***********************************************/

/*
int	print(char *str)
{

}
*/
int ft_printf(const char *format, ...)
{
	va_list args;
    va_start(args, format);
    int	i;

    i = 0;
    while (i < (int)ft_strlen(format))
    {
    	i += print_mod(format + i);
    	print_mod("\n");
    }

    va_end(args);
    return(1);
}