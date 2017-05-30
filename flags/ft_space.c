/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:02:39 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:02:42 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int ft_space_valid(char c)
{
	if ((c == 'd') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'x') \
		|| (c == 'p'))
		return (1);
	else
		return (0);
}

int		ft_space(char *str, char *todo, int start) /* if no sign is going to be written, a blank space is inserted before the value */
{
	int 	i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	if ((ft_char_count(todo, ' ') > 0) && (ft_space_valid(ft_tolower(todo[ft_strlen(todo) - 1])) == 1))
	{
		if (ft_char_count(todo, '+') > 0)
			return (0);
		while (str[start] == ' ')
			start++;
		i = ft_atoi(&str[start]);
		if (i < 0)
			return (0);
		tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
		tmp2 = ft_strdup(&str[start]);
		// tmp2 = ft_strncpy(ft_strnew(ft_strlen(&str[start]) - 1), (const char *)&str[start], (ft_strlen(&str[start] - 2)));
		tmp3 = ft_strjoin(" ", tmp2);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp);
		ft_strdel(&tmp3);
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp2);
	}
	return (0);
}
