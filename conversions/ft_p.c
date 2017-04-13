#include "../ft_printf.h"

int		ft_p(va_list ap, char **s1) /* type pointer? */ 
{
	void	*data;

	data = va_arg(ap, void *);
	ft_print_hex((unsigned int)data);
	*s1 = ft_strinsert(*s1, (char *)data, 1);
	return (0);
}
