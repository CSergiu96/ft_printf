#include "ftprintf.h"


/***********************************************************\
|		Printing characters expecting a single "%" 		    | 
\***********************************************************/


int	print_mod(const char *s)
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