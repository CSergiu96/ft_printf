#include "ftprintf.h"


/***********************************************************\
|			   Returns the length of a string	  			| 
\***********************************************************/
size_t	ft_strlen(const char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}