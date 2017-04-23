#include "ftprintf.h"

int			set_flag(t_toprint *tp, int i, const char *format)
{
	if (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
		format[i] == '#' || format[i] == '0')
	{
		tp->flag = format[i];
		return (i);
	}
	else return (-1);
}


int			set_width(t_toprint *tp, int i, const char *format, va_list args)
{
	if (ft_isdigit(format[i]) )
		{
			tp->width = get_width(format + i);
			return (i);
		}
		else if(format[i] == '*')
		{
			tp->width = va_arg(args,int);
			return (i);
		}
		return (-1);
}

int			set_precision(t_toprint *tp, int i, const char *format, va_list args)
{
	if (format[i] == '.')
		{
			i++;
			if (ft_isdigit(format[i]))
			{
				tp->precision = get_width(format + i);
				return (i);
			}
		else if(format[i] == '*')
			{
				tp->precision = va_arg(args,int);
				return (i);
			}
		}
		return (-1);
}

int			set_specifier(t_toprint *tp, int i, const char *format)
{
	char 	spec[] = "sSpdDioOuUxXcC";
	int		j;

	j = 0;

	while(spec[j] != '\0')
	{
		if (format[i] == spec[j])
		{
			tp->specifier = spec[j];
			return (i);
		}
		j++;
	}
	return (-1);
}

int			set_length(t_toprint *tp, int i, const char *format)
{
	char 	len[] = "hljztL";
	char	c[3];
	int		j;
	int		k;

	j = 0;
	k = 0;
	while(len[j] != '\0')
	{
		if (format[i] == len[j])
		{
			c[k++] = len[j];
			if (format[i + 1] == len[j]) 
				if(len[j] == 'l' || len[j] == 'h')
				c[k++] = len[j];
			c[k + 1] = '\0';
		}
		j++;
	}
	tp->length = ft_strdup(c);
	return (-1);	
}