#include "ftprintf.h"

int			get_width(const char *str)
{
	int rez;

	rez = 0;
	while(ft_isdigit(*str))
	{
		rez *=10;
		rez += *str - '0';
		str++;
	}
	return (rez);
}
/***********************************************************\
|			   Builds a new toprint structure	  			| 
\***********************************************************/
t_toprint	*new_tp()
{
	t_toprint 	*tp;

	tp = (t_toprint*)malloc(sizeof(t_toprint));
	if (tp == NULL)
		return (t_toprint *)(NULL);
	return (tp);
}

/***********************************************************\
|				 Gets all the flags,widh.... 	 	 		| 
\***********************************************************/
#include <stdio.h>
t_toprint	*get_format(const char *format, va_list args)
{
	int			i;
	//
	int a,b,c,d,e;
	//
	t_toprint 	*tp;

	tp = new_tp();
	i = 0;
	while(format[i] != '\0')
	{
		if(!tp->flag)
	a=		set_flag(tp,i,format);
		if(!tp->width)
	b=		set_width(tp,i,format,args);
		if(!tp->precision)
	c=		set_precision(tp,i,format,args);
		if(!tp->length)
	d=		set_length(tp,i,format);
		if(!tp->specifier)
	e=		set_specifier(tp,i,format);
		i++;
	}
	printf("\n\n\n%d%d%d%d%d\n\n\n",a,b,c,d,e);
	return (tp);
}