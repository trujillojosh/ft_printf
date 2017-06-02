/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:34:22 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/01 22:34:24 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_m_len(intmax_t nb)
{
	size_t		i;

	i = 0;
	while ((nb / 10) != 0)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa_m(intmax_t n)
{
	size_t	i;
	char	*re;

	i = ft_m_len(n) - 1;
	if (!(re = (char *)malloc(sizeof(char) * ft_m_len(n) + 1)))
		return (NULL);
	re[i + 1] = '\0';
	if (n < 0)
	{
		re[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		re[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		re[i] = n + '0';
	return (re);
}
