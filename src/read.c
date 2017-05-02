#include "ftprintf.h"

/***********************************************************\
|			Returns the width taken from the string			| 
\***********************************************************/
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
	tp->add = 0;
	return (tp);
}

/***********************************************************\
|				 Gets all the flags,widh.... 	 	 		| 
\***********************************************************/

t_toprint	*get_format(const char *format, va_list args)
{
	int			i;

	t_toprint 	*tp;

	tp = new_tp();
	i = 0;
	i += set_flag(tp,i,format);	
	i += set_width(tp,i,format,args);
	i += set_precision(tp,i,format,args);
	i += set_length(tp,i,format);
	i += set_specifier(tp,i,format);
	if(!tp->specifier)
	{
		print_s("\nWrong format.\n");
		return(NULL);
	}
	return (tp);
}