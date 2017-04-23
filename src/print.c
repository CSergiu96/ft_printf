#include "ftprintf.h"

/***********************************************************\
|				Prints a single character					|
\***********************************************************/
void	print_c(char c)
{
	write(1, &c, 1);
}


/***********************************************************\
|			Prints a string and returns it's length			|
\***********************************************************/
int		print_s(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
/***********************************************************\
|					Prints a integer						|
\***********************************************************/
void	print_i(int nb)
{
	if (nb == -2147483648)
	{
		print_c('-');
		print_c('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		print_c('-');
	}
	if (nb >= 10)
	{
		print_i(nb / 10);
		print_i(nb % 10);
	}
	else
		print_c(nb + '0');
}

/***********************************************************\
|				Prints a floating point number				|
\***********************************************************/
void	print_f(float nb)
{
 	int intpart;
 	int otherpart;
  	float decpart;

  	intpart = (int)nb;
  	decpart  = nb - intpart;
  	while (decpart != (int)decpart)
  		decpart *= 10;
  	otherpart = (int)decpart;
  	print_i(intpart);
  	print_c('.');
  	print_i(otherpart);

}