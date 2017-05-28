/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:44:26 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/26 23:31:13 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 	*ft_find_type(char *str)
{
	int 	i;
	int 	j;
	char 	*ret;

	i = 0;
	j = 0;
	while ((*str != '%') && (*str != '\0'))
		str++;
	if (*str == '%')
		str++;
	while(ft_is_over(str[i], 2))
		i++;
	ret = ft_strnew(i + 1);
	while (j < i)
	{
		ret[j] = *str;
		j++;
		str++;
	}
	ret[j] = '\0';
	return (ret);
}

static int 	ft_dispatch(va_list ap, char **todo, char **str, int specs)
{
	char c;

	if (ft_strlen(*todo) > 0)
		c = (*todo)[ft_strlen(*todo) - 1];
	else
		return (-1);
	if ((c == 's') || c == 'S')
		return (ft_s(ap, str, -1, specs));
	else if ((c == 'd') || (c == 'i') || (c == 'D'))
		return (ft_d(ap, str, specs));
	else if ((c == 'c') || (c == 'C'))
		return (ft_c(ap, str, specs));
	else if (c == '%')
		return (ft_percent(str));
	else if (c == 'p')
		return (ft_p(ap, str));
	else if ((c == 'o') || (c == 'O'))
		return (ft_o(ap, str, specs));
	else if ((c == 'u') || (c == 'U'))
		return (ft_u(ap, str, specs));
	else if (c == 'x')
		return (ft_x(ap, str, specs));
	else if (c == 'X')
		return (ft_up_x(ap, str, specs));
	return (-1);
}

static int	ft_specs(char *tmp)
{
	int 	i;

	i = 0;
	if (ft_char_count(tmp, 'l') > 0)
	{
		while ((*tmp != '\0') && (*tmp != 'l'))
			tmp++;
		if ((*tmp == 'l') && (*(tmp + 1) == 'l'))
			i = 4;
		else
			i = 3;
	}
	else if (ft_char_count(tmp, 'h') > 0)
	{
		while ((*tmp != '\0') && (*tmp != 'h'))
			tmp++;
		if ((*tmp == 'h') && (*(tmp + 1) == 'h'))
			i = 2;
		else
			i = 1;
	}
	else if (ft_char_count(tmp, 'j') > 0)
		i = 5;
	else if (ft_char_count(tmp, 'z') > 0)
		i = 6;
	return (i);
}

static int	ft_flags(va_list ap, char **todo, char **str)
{
	int		i;
	int 	j;
	int 	prec;

	i = 0;
	ft_strinsert(*str, "", 0);
	while ((**str != '%') && (**str != '\0'))
		(*str)++;
	if (ft_strinsert("", "", 2))
		i = ft_strlen(ft_strinsert("", "", 2)); //i == start
	if ((prec = find_precision(*todo)) < -1) //-1 reps no precison
		return (-1);
	j = ft_specs(*todo);
	if (ft_strlen(*todo) == 0)
		return (0);
	else if (ft_tolower((*todo)[ft_strlen(*todo) - 1]) == 's')
		ft_s(ap, str, prec, j);
	else
		if (ft_dispatch(ap, todo, str, j) < 0)
		{
			return (-1);
		}
	if (prec >= 0)
		ft_precision(ft_strinsert("", "", 2), *todo, i, prec);
	ft_width(ft_strinsert("", "", 2), *todo, i);
	ft_plus(ft_strinsert("", "", 2), *todo, i);
	ft_space(ft_strinsert("", "", 2), *todo, i);
	ft_hash(ft_strinsert("", "", 2), *todo, i); //had i = hash originally but didn't see the need
	ft_0(ft_strinsert("", "", 2), *todo, i);
	ft_minus(ft_strinsert("", "", 2), *todo, i);
	*str = ft_strinsert(*str, "", 0);
	return (1);
}

int			ft_next_arg(va_list ap, char **str, int i)
{
	char	*type;
	
	type = ft_find_type(*str);
	if (ft_flags(ap, &type, str) < 0)
	{
		ft_strdel(&type);
		return (-1);
	}
	ft_strdel(&type);
	return (0);
}
