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
			print_tp(tp, args);
			if(!tp)
				exit(0);
			len+= tp->add;
/*
			if (tp->flag)
				printf("\x1b[32m""\nflag :%c",tp->flag);
			if (tp->width)
				printf("\x1b[33m""\nwidth :%d",tp->width);
			if (tp->precision)
				printf("\x1b[34m""\nprecision :%d",tp->precision);
			if (tp->length)
				printf("\x1b[35m""\nlength :%d",tp->length);
			if (tp->specifier)
				printf("\x1b[36m""\nspecifier :%c\n",tp->specifier);
*/		}

	}
	va_end(args);
    return (len);
}