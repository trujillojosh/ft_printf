/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:44:26 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/10 19:00:22 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_find_type(char **str)
{
	char	*s1;
	char 	c;

	s1 = ft_strdup(*str);
	c = 0;
	while ((*s1 != '%') && (*s1 != '\0'))
		s1++;
	if (*s1 == '%')
		s1++;
	if ((*(s1 + 1) != ' ') && (*(s1 + 1) != '\0'))
	{
		return ('\0');
	}
	else
		return (*s1);
	// if (*s1 == '\0') //handles no percents
	// {
	// 	return (c);
	// }
	// else if (*(s1 + 1) == ' ')
	// {
	// 	// ft_strdel(&s1);
	// 	//c = create function to handle multiple
	// 	return (c); //need to fix later to hold multiple
	// }
	// else
	// {
	// 	c = *s1;
	// 	return (*s1);
}

static int 	ft_dispatch(va_list ap, char c, char **str)
{
	if (c == 's')
		return(ft_s(ap, str));
	return (0);
}

int			ft_next_arg(va_list ap, char **str, int i)
{
	char	type;
	
	type = ft_find_type(str);
	if (type)
	{
		if (ft_dispatch(ap, type, str) < 0)
			return (-1);
		// ft_putchar(type);
	}
	else
	{
		ft_putstr("no type");
	}
	return (0);
}
