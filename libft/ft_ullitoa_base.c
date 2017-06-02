/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 01:43:25 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/02 01:43:27 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_ullint_len_ext(unsigned long long nb, int base)
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

char		*ft_ullitoa_base(unsigned long long value, int base)
{
	int		i;
	char	*re;

	i = 1;
	if (base == 10)
		return (ft_itoa_ull(value));
	i = ft_ullint_len_ext(value, base);
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
