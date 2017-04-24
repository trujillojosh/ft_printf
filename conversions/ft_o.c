/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:47:05 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:47:07 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_o(va_list ap, char **s1) /* Type octal Integer */ 
{
	unsigned int 	res;
	char			*tmp;

	res = va_arg(ap, unsigned int);
	tmp = ft_uitoa_base(res, 8);
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
