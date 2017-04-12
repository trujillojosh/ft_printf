/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:10:15 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/11 17:18:12 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Searches for percent sign within s1, and inserts s2 between two words */

char	*ft_strinsert(char *s1, char *s2)
{
	char	*res;
	int		i;
	
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) - 2));
	while (*s1 != '%')
		res[i++] = *s1++;
	while (*s2 != '\0')
		res[i++] = *s2++;
	while (*s1 != '\0')
	{
		while ((*s1 != ' ') && (*s1 != '\0'))
			s1++;
		res[i] = *s1;
		i++;
		s1++;
	}
	res[i] = '\0';
	return (res);
}
