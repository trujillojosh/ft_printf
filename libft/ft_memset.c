/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:54:31 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 14:47:26 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(str));
	s = str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
