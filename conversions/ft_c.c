/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:50 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:46:52 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_c(va_list ap, char **s1)/* character type */ 
{
	char 	a[2];

	a[0] = va_arg(ap, int);
	a[1] = '\0';
	*s1 = ft_strinsert(*s1, a, 1);
	return (0);
}
