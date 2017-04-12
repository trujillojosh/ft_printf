#include "../ft_printf.h"

int		ft_c(va_list ap, char **s1) /* character type */ 
{
	char 	a[2];

	a[0] = va_arg(ap, int);
	a[1] = '\0';
	*s1 = ft_strinsert(*s1, a);
	return (0);
}
