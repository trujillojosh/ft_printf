/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:10 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:01:12 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_x(va_list ap, char **s1) /* Unsigned hexadecimal integer */ 
{
	unsigned int 	res;
	char 			*tmp;
	int 			i;

	i = 0;
	res = va_arg(ap, unsigned int);
	tmp = ft_uitoa_base(res, 16);
	while (tmp[i] != '\0')
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
