/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 01:42:57 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/02 01:43:04 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libft.h"

static int		ft_usint_len_ext(unsigned short nb, int base)
{
	int	i;

	i = 0;
	while ((nb / base) != 0)
	{
		i++;
		nb = nb / base;
	}
	i++;
	return (i);
}
char		*ft_usitoa_base(unsigned short value, int base)
{
	int		i;
	char	*re;

	i = 1;
	if (base == 10)
		return (ft_itoa_us(value));
	i = ft_usint_len_ext(value, base);
	re = (char *)malloc(sizeof(char) * (i + 1));
	re[i] = '\0';
	i--;
	while (i >= 0)
	{
		if ((value % base) > 9)
			re[i] = (value % base) + 55;
		else
			re[i] = (value % base) + 48;
		value = value / base;
		i--;
	}
	return (re);
}
