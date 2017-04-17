#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int		ft_printf(const char *format, ...);

void	print_mod(char *s);
#endif