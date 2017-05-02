#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct 	s_toprint
{
	char	flag;
	int		width;
	int		precision;
	int 	length;
	char	specifier;
	int		add;/*whole format length so i can continue reading the format*/
}				t_toprint;


/**********************\
|  		 fct.c         |
\**********************/
size_t		ft_intlen(int n);
size_t		ft_strlen(const char *src);
int			ft_isdigit(int c);
char		*ft_strdup(const char *src);
char		*ft_strcpy(char *dest, const char *src);

/**********************\
|  		 fct2.c        |
\**********************/
void		aux(int n, int b, char *ans, int *p);
char		*ft_itoa_base(int value, int base);

/**********************\
|  		 print.c       |
\**********************/
void		print_i(int nb);
void		print_c(char c);
int			print_s(char *s);
void		print_f(float nb);

/**********************\
|       spec_d.c       |
\**********************/
void	print_s_d(t_toprint *tp, va_list args);

/**********************\
|      print_tp.c      |
\**********************/
int		print_tp(t_toprint *tp, va_list args);

/**********************\
|		 write.c       |
\**********************/
int			print_mod(const char *s);
int			print(const char *str, va_list args);

/**********************\
|  	    format.c       |
\**********************/
int			set_flag(t_toprint *tp, int i, const char *format);
int			set_width(t_toprint *tp, int i, const char *format, va_list args);
int			set_precision(t_toprint *tp, int i, const char *format, va_list args);
int			set_length(t_toprint *tp, int i, const char *format);
int			set_specifier(t_toprint *tp, int i, const char *format);

/**********************\
|  		 read.c        |
\**********************/
int			get_width(const char *str);
t_toprint	*new_tp();
t_toprint	*get_format(const char *format, va_list args);

/**********************\
|		printf.c       |
\**********************/
int			ft_printf(const char *format, ...);
#endif