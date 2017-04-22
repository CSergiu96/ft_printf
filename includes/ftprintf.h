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
	char	flag;
	int		width;
	int		precision;
	int		length;
	char	*specifier;
}				t_format;


/**********************\
|  		 fct.c         | 
\**********************/
size_t	ft_strlen(const char *src);

/**********************\
|  		 print.c       | 
\**********************/
void	print_i(int nb);
void	print_c(char c);
int		print_s(char *s);
void	print_f(float nb);

/**********************\
|		 write.c       | 
\**********************/
int		print_mod(const char *s);
int		print(const char *str, va_list args);

/**********************\
|		printf.c       | 
\**********************/
int		ft_printf(const char *format, ...);
#endif