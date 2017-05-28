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

int		ft_0(char *str, char *todo, int opt) /* Left pads # with zeroes isntead of spaces */
{
	char	*tmp;
	char 	*tmp2;
	int 	i;

	i = 0;
	if (ft_char_count(todo, '0') > 0) //wtf was i thinking
	{
		if (ft_0_valid(todo) == 0)
			return (0);
		while (str[i] == ' ')
			i++;
		if ((opt == 1) && ((todo[ft_strlen(todo) - 1] == 'x') || (todo[ft_strlen(todo) - 1] == 'X')))
		{
			i += 2;
			tmp = ft_memset(ft_strnew(i), '0', i);
			tmp[1] = todo[ft_strlen(todo) - 1];
		}
		else
			tmp = ft_memset(ft_strnew(i), '0', i);
		tmp2 = ft_strjoin(tmp, &str[i]);
		ft_strdel(&tmp);
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp2);
	}
	return (0);
}
