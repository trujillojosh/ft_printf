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

int		ft_o(va_list ap, char **s1, char *todo) /* Type octal Integer */ 
{
	void			*res;
	char			*tmp;

	res = va_arg(ap, void *);
	tmp = ft_itoa_dispatch(res, todo, 8);
	// tmp = ft_uitoa_base((unsigned int)res, 8);
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
