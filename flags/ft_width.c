/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:29:25 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/22 15:58:13 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_find_width(char **todo)
{
	int		i;
	int		j;
	char	*length;

	j = 0;
	i = ft_strlen(*todo) - 2;
	while ((ft_isdigit((*todo)[i]) == 1) && (ft_isdigit((*todo)[i - 1]) != 0))
		i--;
	if (i < (ft_strlen(*todo) - 2))
	{
		if (((*todo)[i] == '0') && ((i + 1) != (ft_strlen(*todo) - 2)))
			i++;
		j = (ft_strlen(*todo) - 2) - i + 1;
		length = ft_strnew(j);
		length = ft_strncpy(length, &(*todo)[i], j);
		j = ft_atoi(length);
		ft_strdel(&length);
	}
	return (j);
}

int		ft_width(char **str, char **todo, int start)
{
	int		width;
	char	*tmp;
	char	*tmp2;
	int 	test = 0;

	width = ft_find_width(todo) - ft_strlen(&(*str)[start]);
	if ((ft_strlen(&(*str)[start]) < width) && (width > 0))
	{
		tmp = ft_strncpy(ft_strnew(start), (const char *)*str, start);
		tmp2 = ft_memset(ft_strnew(width), ' ', width);
		ft_strinsert(ft_strjoin(tmp, ft_strjoin(tmp2, &(*str)[start])), "", 3);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	else
		test = ft_strlen(&(*str)[start]);
	return (0);
}
