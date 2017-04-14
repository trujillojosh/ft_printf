/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:59:24 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:59:38 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_u(va_list ap, char **s1) /* type unsigned int */ 
{
	unsigned int 	res;

	res = va_arg(ap, unsigned int);
	*s1 = ft_strinsert(*s1, ft_uitoa_base(res, 10), 1);
	return (0);
}
