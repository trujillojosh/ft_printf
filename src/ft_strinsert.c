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

#include "../includes/ft_printf.h"

/* Searches for percent sign within s1, and inserts s2 between two words */
/* mode 0 strjoin str and s1 */
/* mode 1 strjoin str and s1, increment s1 until next */
/* mode 2 returns string stored in static string str */
/* mode 3 replaces value of str with first param(s1) */

static char *ft_helper(int mode, char **str, char **s1)
{
	if (mode == 3)
	{
		if (str)
			ft_strdel(str);
		*str = ft_strdup(*s1);
	}
	if (*str)
		return (*str);
	else
		return (NULL);
}

char		*ft_strinsert(char *s1, char *s2, int mode)
{
	static char 	*str;
	char			*res;
	char 			*tmp;
	int				i;
	
	i = 0;
	if (mode == 0)
	{
		res = ft_strnew(ft_strlen(s1));
		while ((*s1 != '%') && (*s1 != '\0'))
			res[i++] = *s1++;
		if (str)
		{
			tmp = ft_strjoin(str, res);
			ft_strdel(&str);
			str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
			str = ft_strdup(res);
		ft_strdel(&res);
		return (s1);
	}
	else if ((mode == 2) || (mode == 3))
		return (ft_helper(mode, &str, &s1));
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - 2);
	while (*s2 != '\0')
		res[i++] = *s2++;
	while (ft_is_over(*s1, 1))
		s1++;
	res[i] = '\0';
	if (str)
	{
		tmp = ft_strjoin(str, res);
		ft_strdel(&str);
		str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
		str = ft_strdup(res);
	ft_strdel(&res);
	return (s1);
}