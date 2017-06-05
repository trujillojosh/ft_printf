/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:47:18 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:47:20 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_p(va_list ap, char **s1) /* type pointer */ 
{
	void	*data;
	char	*res;
	char 	*tmp;
	int 	i;

	i = 0;
	data = va_arg(ap, void *);
	tmp = ft_itoa_base((unsigned long int)data, 16);
	res = ft_strjoin("0x7fff", tmp);
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	*s1 = ft_strinsert(*s1, res, 1);
	ft_strdel(&tmp);
	ft_strdel(&res);
	return (0);
}
