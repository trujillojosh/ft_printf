/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:45 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:01:46 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_hash(char *str, char *todo, int start)
{
	int 	i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	if (ft_char_count(todo, '#') > 0)
	{
		while (str[start] == ' ')
			start++;
		i = ft_atoi(&str[start]);
		tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
		tmp2 = ft_strncpy(ft_strnew(ft_strlen(&str[start]) - 1), (const char *)&str[start], (ft_strlen(&str[start] - 2)));
		if (todo[ft_strlen(todo) - 1] == 'o')
			tmp3 = ft_strjoin("0", tmp2);
		else if (todo[ft_strlen(todo) - 1] == 'x')
			tmp3 = ft_strjoin("0x", tmp2);
		else if (todo[ft_strlen(todo) - 1] == 'X')
			tmp3 = ft_strjoin("0X", tmp2);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp);
		ft_strdel(&tmp3);
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp2);
		return (1);
	}
	return (0);
}