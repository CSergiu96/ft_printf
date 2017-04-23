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
	return (i + 1);
}


/***********************************************************\
|	   	Printing characters + one specifier at a time       |
\***********************************************************/
#include <stdio.h>
int		print(const char *format, va_list args)
{
	int len;
	t_toprint *tp;

	len = 0;
	while (len < (int)ft_strlen(format))
	{
		len += print_mod(format+len);
		/*Prints the string untill the first specifier*/
		if( *(format + len- 1 ) != '\0')
		{
			tp = get_format(format + len, args);
			/*if(*(format + len) == 'c')
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
			//////////////////////////////////////
			//////////////remove//////////////////
			//////////////////////////////////////
			if(*(format + len) == 'f')
			{
           		 print_f(va_arg(args, double));
           		 len++;
			}*/
		}

	}
	if (tp->flag)
		printf("\nflaaag :%c",tp->flag);
	if (tp->width)
		printf("\nwidth :%d",tp->width);
	if (tp->precision)
		printf("\nprecision :%d",tp->precision);
	if (tp->length)
		printf("\nlength :%s",tp->length);
	if (tp->specifier)
		printf("\nspecifier :%c",tp->specifier);
			
	va_end(args);
    return (len);
}