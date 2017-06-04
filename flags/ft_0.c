/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:23 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:01:27 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int ft_0_valid(char *todo)
{
	int 	i;

	i = 0;
	while ((todo[i] != '0') && (todo[i] != '\0'))
	{
		if ((ft_isdigit(todo[i])) || (todo[i] == '.'))
			return (0);
		i++;
	}
	if (todo[i] == '0')
		return (1);
	return (0);
}

int		ft_0(char *str, char *todo, int opt, int prec) /* Left pads # with zeroes isntead of spaces */
{
	char	*tmp;
	char 	*tmp2;
	char 	*tmp3;
	int 	i;

	i = 0;
	if ((ft_char_count(todo, '0') > 0) && (ft_char_count(todo, '-') == 0))
	{
		if (ft_0_valid(todo) == 0)
			return (0);
		while (str[i] == ' ')
			i++;
		if ((str[i] == '+') || (str[i] == '-'))
		{
			tmp3 = ft_strnew(1);
			tmp3[0] = str[i];
		}
		if ((opt == 1) && ((todo[ft_strlen(todo) - 1] == 'x') || (todo[ft_strlen(todo) - 1] == 'X')))
		{
			i += 2;
			tmp = ft_memset(ft_strnew(i), '0', i);
			tmp[1] = todo[ft_strlen(todo) - 1];
		}
		else
			tmp = ft_memset(ft_strnew(i), '0', i);
		if ((str[i] == '+') || (str[i] == '-'))
		{
			tmp2 = ft_strjoin(tmp3, tmp);
			tmp = ft_strdup(tmp2);
			ft_strdel(&tmp3);
			ft_strdel(&tmp2);
			i++;
		}
		tmp2 = ft_strjoin(tmp, &str[i]);
		ft_strdel(&tmp);
		i = 0;
		while ((ft_char_count(tmp2, '0') >= prec) && (prec > 0) && (tmp2[i] != '\0'))
		{
			if ((ft_isdigit(tmp2[i]) == 1) && (tmp2[i] != '0'))
				break ;
			else if (((ft_char_count(tmp2, '0') - 1) == 1) && (tmp2[ft_strlen(tmp2) - 1] == '0'))
				break ;
			if (tmp2[i] == '0')
				tmp2[i] = ' ';
			i++;
		}
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp2);
	}
	return (0);
}
