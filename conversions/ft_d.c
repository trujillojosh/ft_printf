#include "../ft_printf.h"

/* type decimal signed int, i conversion is same as d */ 
int		ft_d(va_list ap, char **s1)
{
	char	*digit;

	digit = ft_itoa(va_arg(ap, int));
	*s1 = ft_strinsert(*s1, digit, 1);
	ft_strdel(&digit);
	return (0);
}
