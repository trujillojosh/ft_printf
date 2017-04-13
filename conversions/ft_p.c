#include "../ft_printf.h"

int		ft_p(va_list ap, char **s1) /* type pointer? */ 
{
	void	*data;
	char	*res;
	int 	i;

	i = 0;
	data = va_arg(ap, void *);
	res = ft_strjoin("0x7fff", ft_itoa_base((unsigned long int)data, 16));
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	*s1 = ft_strinsert(*s1, res, 1);
	ft_strdel(&res);
	return (0);
}
