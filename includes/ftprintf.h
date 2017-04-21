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

typedef struct 	s_format
{
	void	*content;
	char	flag;
	int		width;
	int		precision;
	int		length;
	char	*specifier;
}				t_format;

int	ft_printf(const char *format, ...);

size_t	ft_strlen(const char *src);
int	print_mod(const char *s);
#endif