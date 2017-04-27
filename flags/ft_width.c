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

static int		ft_find_width(char *todo)
{
	int		i;
	int		j;
	char	*length;

	j = 0;
	if ((i = ft_strlen(todo) - 2) < 0)
		i = 0;
	while (ft_isdigit((todo)[i]) == 1)
	{
		if (i != 0)
			if (ft_isdigit((todo)[i - 1] == 0))
				break ;
		if (ft_isdigit(todo[i - 1]) != 0)
			i--;
		else
			break ;
		if (i < 0)
			break ;
	}
	if (i <= (int)(ft_strlen(todo) - 2))
	{
		if (i == -1)
			i++;
		if (((todo)[i] == '0') && ((i + 1) != (ft_strlen(todo) - 2)))
			i++;
		j = (ft_strlen(todo) - 2) - i + 1;
		length = ft_strncpy(ft_strnew(j), &todo[i], j);
		j = ft_atoi(length);
		ft_strdel(&length);
	}
	return (j);
}
int		ft_width(char *str, char *todo, int start)
{
	int		width;
	char	*tmp;
	char	*tmp2;
	char 	*tmp3;

	width = ft_find_width(todo) - (int)ft_strlen(&str[start]);
	if (str[ft_strlen(&str[start]) - 1] == '\n')
		width++;
	if (width > 0)
	{
		if ((ft_char_count(todo, ' ') > 0) || (ft_char_count(todo, '+') > 0))
		{
			if (ft_atoi(&str[start]) >= 0)
				width--;
		}
		if (ft_char_count(todo, '#') > 0)
		{
			width--;
			if ((todo[ft_strlen(todo) - 1] == 'x') || (todo[ft_strlen(todo) - 1] == 'X'))
				width--;
		}
		if (width > 0)
		{
			if (start > 0)
			{
				tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
				// tmp2 = ft_memset(ft_strnew(width), ' ', width);
				tmp3 = ft_strjoin(tmp2, &str[start]);
				ft_strdel(&tmp2);
				tmp2 = ft_strjoin(tmp, tmp3);
				ft_strinsert(tmp2, "", 3);
				ft_strdel(&tmp);
				ft_strdel(&tmp2);
				ft_strdel(&tmp3);
			}
			else
			{
				tmp = ft_strdup(str);
				tmp2 = ft_memset(ft_strnew(width), ' ', width);
				tmp3 = ft_strjoin(tmp2, str);
				ft_strinsert(tmp3, "", 3);
				ft_strdel(&tmp);
				ft_strdel(&tmp2);
				ft_strdel(&tmp3);
			}			
		}
	}
	return (0);
}
