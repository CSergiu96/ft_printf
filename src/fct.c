#include "ftprintf.h"

/***********************************************************\
|			   Returns the muber of digits 		  			| 
\***********************************************************/
size_t	ft_intlen(int n)
{
	int i;

	i = 0;
	while (n)
	{
		i++;
		n/=10;
	}
	return (i);
}
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

/***********************************************************\
|			   Returns 1 if it's a digit or 0 if not		| 
\***********************************************************/
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/***********************************************************\
|			   Returns a string duplicate 					| 
\***********************************************************/
char	*ft_strdup(const char *src)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	else
	{
		ft_strcpy(new, src);
		return (new);
	}
}
/***********************************************************\
|			   Copyes a string into another					| 
\***********************************************************/
char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (i != ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
