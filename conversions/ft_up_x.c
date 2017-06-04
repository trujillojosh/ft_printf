/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:03 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:01:05 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_up_x(va_list ap, char **s1, char *todo) /* Unsigned hexadecimal integer (uppercase) */ 
{
	void	*res;
	char 	*tmp;

	res = va_arg(ap, void *);
	tmp = ft_itoa_dispatch(res, todo, 16);
	// *s1 = ft_strinsert(*s1, ft_uitoa_base((unsigned int)res, 16), 1);
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
