/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:21 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:46:25 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	int 		j;
	int 		k;
	char 		*str;
	char 		*tmp;

	i = ft_char_count((char *)input, '%');
	j = 0;
	k = 0;
	if (i == 0)
	{
		ft_putstr(input);
		return (ft_strlen(input));
	}
	str = ft_strdup(input);
	tmp = str;
	va_start(ap, input);
	while (i > 0)
	{
		j = ft_next_arg(ap, &str);
		if (j < 0)
			break ;
		else if (j == 1)
			k++;
		i--;
	}
	if (tmp)
		ft_strdel(&tmp);
	va_end(ap);
	ft_putstr(ft_strinsert("", "", 2));
	return (ft_strlen(ft_strinsert("", "", 2)) + k);
}
