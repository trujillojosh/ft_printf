#include "../ft_printf.h"

int		ft_s(va_list ap, char **s1) /* type string */ 
{
	char	*var;

	var = va_arg(ap, char *);
	*s1 = ft_strinsert(*s1, var, 1);
	return (0);
}
