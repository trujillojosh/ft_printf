/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:44:26 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/24 17:39:01 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 	*ft_find_type(char *str)
{
	int 	i;
	int 	j;
	char 	*ret;

	i = 0;
	j = 0;
	while ((*str != '%') && (*str != '\0'))
		str++;
	if (*str == '%')
		str++;
	while(ft_is_over(str[i], 2))
		i++;
	ret = ft_strnew(i + 1);
	while (j < i)
	{
		ret[j] = *str;
		j++;
		str++;
	}
	ret[j] = '\0';
	return (ret);
}

static int 	ft_dispatch(va_list ap, char c, char **str)
{
	if (c == 's')
		return (ft_s(ap, str));
	else if ((c == 'd') || (c == 'i'))
		return (ft_d(ap, str));
	else if (c == 'c')
		return (ft_c(ap, str));
	else if (c == '%')
		return (ft_percent(str));
	else if (c == 'p')
		return (ft_p(ap, str));
	else if (c == 'o')
		return (ft_o(ap, str));
	else if (c == 'u')
		return (ft_u(ap, str));
	else if (c == 'x')
		return (ft_x(ap, str));
	else if (c == 'X')
		return (ft_up_x(ap, str));
	return (-1);
}

static int	ft_flags(va_list ap, char **todo, char **str)
{
	int		i;
	//char	*tmp;

	i = 0;
	if (ft_strinsert("", "", 2))
		i = ft_strlen(ft_strinsert("", "", 2)); //i == start
	if (ft_dispatch(ap, (*todo)[ft_strlen(*todo) - 1], str) < 0)
		return (-1);
	ft_width(ft_strinsert("", "", 2), todo, i);
	ft_plus(ft_strinsert("", "", 2), todo, i);
	return (1);
}

int			ft_next_arg(va_list ap, char **str, int i)
{
	char	*type;
	
	type = ft_find_type(*str);
	if (ft_flags(ap, &type, str) < 0)
	{
		ft_strdel(&type);
		return (-1);
	}
	ft_strdel(&type);
	return (0);
}
