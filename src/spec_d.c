#include "ftprintf.h"

void	print_s_d(t_toprint *tp, va_list args)
{
	if(tp->specifier == 'd')
	print_i(va_arg(args,int));
}
