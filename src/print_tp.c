#include "ftprintf.h"

int		print_tp(t_toprint *tp, va_list args)
{
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
	if(tp->specifier == 'd' || tp->specifier == 'i')
		print_s_d(tp,args);
		//print_i(va_arg(args,int));

	return(1);
}