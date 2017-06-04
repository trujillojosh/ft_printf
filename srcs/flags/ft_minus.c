/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:02:25 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:02:27 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_minus(char *str, char *todo, int opt) /* Left-justify within given field width, right justification is default */
{
	char	*tmp;
	char	*tmp2;
	char 	*tmp3;
	char 	c;
	int 	i;

	i = 0;
	if (ft_char_count(todo, '-') > 0)
	{
		if (opt == 2)
		{
			i++;
			c = todo[ft_strlen(todo) - 1];
			if ((c == 'x') || (c == 'X'))
			{
				tmp = ft_strncpy(ft_strnew(2), str, 2);
				i++;
			}
			else
				tmp = ft_strncpy(ft_strnew(1), str, 1);
		}
		else
			tmp = NULL;
		while (str[i] == ' ')
			i++;
		tmp2 = ft_memset(ft_strnew(i), ' ', i);
		if (tmp)
		{
			tmp3 = ft_strjoin(tmp, &str[i]);
			ft_strdel(&tmp);
		}
		else
			tmp3 = ft_strdup(&str[i]);
		tmp = ft_strjoin(tmp3, tmp2);
		ft_strdel(&tmp2);
		ft_strdel(&tmp3);
		ft_strinsert(tmp, "", 3);
	}
	return (0);
}
