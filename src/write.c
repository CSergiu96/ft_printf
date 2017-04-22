#include "ftprintf.h"

/***********************************************************\
|	 Printing characters until a single "%" is occurred  	| 
\***********************************************************/
int		print_mod(const char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0' && !(s[i] == '%' && s[i + 1] != '%'))
	{
		if (s[i] == '%'  && s[i + 1] == '%')
			i++;
		write(1, &s[i], 1);
		i++;
	}
	return(i + 1);
}


/***********************************************************\
|	   	Printing characters + one specifier at a time       |
\***********************************************************/

int		print(const char *format, va_list args)
{
	int len;

	len = 0;
	while (len < (int)ft_strlen(format))
	{
		len += print_mod(format+len);
		if( *(format + len- 1 ) != '\0')
		{
			if(*(format + len) == 'c')
			{
				print_c(va_arg(args,int));
				len++;
			}
			if(*(format + len) == 'd')
			{
				print_i(va_arg(args,int));
				len++;
			}
			if(*(format + len) == 's')
			{
           		 print_s(va_arg(args, char *));
           		 len++;
			}
			if(*(format + len) == 'f')
			{
           		 print_f(va_arg(args, double));
           		 len++;
			}
		}

	}
	va_end(args);
    return(len);
}