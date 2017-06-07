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

#include "../../includes/ft_printf.h"
#include <stdio.h>

static int ft_0_valid(char *todo)
{
	int 	i;

	i = 0;
	if (ft_char_count(todo, '0') == 0)
		return (0);
	if ((ft_char_count(todo, ' ') > 0) || (ft_char_count(todo, '-') > 0))
		return (0);
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

static void	cases_0(char **str, int opt, int i, int start)
{
	char 	*tmp;
	char 	*tmp2;
	char 	*tmp3;

	if (opt == 0)
		return ;
	if (opt == 1)
		tmp = ft_strdup("+");
	else if (opt == 2)
		tmp = ft_strdup("-");
	else if (opt == 3)
		tmp = ft_strdup("0x");
	else
		tmp = ft_strdup("0X");
	tmp3 = ft_strncpy(ft_strnew(start), *str, (start));
	tmp2 = ft_strjoin(tmp, (&(*str)[start]));
	ft_strdel(str);
	*str = ft_strjoin(tmp3, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
}

static int 	get_opt(char *todo, char *str, int i)
{
	char 	c;

	c = todo[ft_strlen(todo) - 1];
	if (ft_char_count(todo, '#') > 0)
	{
		if (c == 'x')
			return (3);
		else if (c == 'X')
			return (4);
	}
	else if (str[i] == '+')
		return (1);
	else if (str[i] == '-')
		return (2);
	return (0);

}

static void prec_0(char **str, int prec, int i)
{
	if ((prec <= 0) || (ft_strlen(*str) == 1))
		return ;
	while ((ft_char_count((&(*str)[i]), '0') >= prec) && ((*str)[i] != '\0'))
	{
		if ((ft_isdigit((*str)[i]) == 1) && ((*str)[i] != '0'))
			break ;
		if ((*str)[i] == '0')
		{
			if (((*str)[i + 1] == '0') && (ft_strlen(&(*str)[i + 1]) == 1))
				break ;
			(*str)[i] = ' ';
		}
		i++;
	}
}

int 		ft_0(char *str, char *todo, int start, int prec)
{
	int 	opt;
	int 	i;
	char 	*tmp;
	char 	*tmp2;
	char 	*tmp3;

	if (ft_0_valid(todo) == 0)
		return (0);
	i = start;
	while (str[i] == ' ')
		i++;
	if (i == 0)
		return (0);
	opt = get_opt(todo, str, i);
	tmp = ft_memset(ft_strnew(i - start), '0', (i - start));
	if ((opt == 1) || (opt == 2))
		i++;
	tmp2 = ft_strncpy(ft_strnew(start), str, start);
	tmp3 = ft_strjoin(tmp2, tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	tmp = ft_strjoin(tmp3, &str[i]);
	cases_0(&tmp, opt, i, start);
	prec_0(&tmp, prec, start);
	ft_strinsert(tmp, "" , 3);
	ft_strdel(&tmp);
	ft_strdel(&tmp3);
	return (0);
}
