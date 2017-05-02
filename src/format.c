#include "ftprintf.h"

int			set_flag(t_toprint *tp, int i, const char *format)
{
	if (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
		format[i] == '#' || format[i] == '0')
	{
		tp->flag = format[i];
		tp->add += 1;
		return (1);
	}
	return (0);
}

int			set_width(t_toprint *tp, int i, const char *format, va_list args)
{
	if (ft_isdigit(format[i]) )
		{
			tp->width = get_width(format + i);
			tp->add += ft_intlen(tp->width);
			return (ft_intlen(tp->width));
		}
		else if(format[i] == '*')
		{
			tp->width = va_arg(args,int);
			tp->add += 1;
			return (1);
		}
		return (0);
}

int			set_precision(t_toprint *tp, int i, const char *format, va_list args)
{
	if (format[i] == '.')
		{
			i++;
			if (ft_isdigit(format[i]))
			{
				tp->precision = get_width(format + i);
				tp->add += ft_intlen(tp->precision) + 1;
				return (ft_intlen(tp->precision) + 1);
			}
		else if(format[i] == '*')
			{
				tp->precision = va_arg(args,int);
				tp->add += 2;
				return (2);
			}
		}
		return (0);
}

int			set_length(t_toprint *tp, int i, const char *format)
{
	char 	len[] = "hljztL";
	int		j;
	j = 0;
	while(len[j] != '\0')
	{
		if (format[i] == len[j])
		{
			tp->length = j + 1;
			if (format[i + 1] == len[j] && (len[j] == 'l' || len[j] == 'h'))
			{
				tp->length += 10; 
				tp->add += 2;
				return(2);
			}
			tp->add += 1;
			return(1);
		}
		j++;
	}
	return(0);

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
			tp->add += 1;
			return (1);
		}
		j++;
	}
	return (0);
}