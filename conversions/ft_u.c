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

int		ft_u(va_list ap, char **s1, int spec) /* type unsigned int */ 
{
	void	*res;

	res = va_arg(ap, void *);
	*s1 = ft_strinsert(*s1, ft_uitoa_base((unsigned int)res, 10), 1);
	return (0);
}
