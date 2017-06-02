/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:56 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:46:58 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* type decimal signed int, i conversion is same as d */ 

int		ft_d(va_list ap, char **s1, char *todo)
{
	void	*digit;

	digit = va_arg(ap, void *);
	*s1 = ft_strinsert(*s1, ft_itoa_dispatch(digit, todo, 10), 1);
	return (0);
}
