#include "ftprintf.h"




#include <stdio.h>
void f(char *s, int *i)
{
	while(s[*i] != '\0')
	{
		write(1,&s[*i],1);
		i++;
	}
}
void f2(int *x)
{
	(*x)++;
}
int	main(void)
{
	//ft_printf("abcde%xyzasdf%asdfs%as");
	int x;
	x = 2;
	int *p = &x;
	
	f2(p);
	//f("xxyyzz",p);
	printf("%d %d",*p,x);
	return(0);
}