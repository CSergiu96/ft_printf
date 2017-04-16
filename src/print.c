#include "ftprintf.h"

void	f(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1,"a",1);
		j++;
	}
}
