/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:21 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/09 16:30:05 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list		ap;
	int			i;
	int			j;
	int			k;
	int 		l;
	char		*str;

	i = ft_char_count((char *)input, '%');
	l = 0;
	k = 0;
	// ft_putstr("\n\ninput was: \"");
	// ft_putstr(input);
	// ft_putstr("\"\n\n");
	// write(1, ">>>", 3);
	// write(1, input, ft_strlen(input));
	// write(1, "\n", 1);
	if (i == 0)
	{
		ft_putstr(input);
		return (ft_strlen(input));
	}
	str = ft_strdup(input);
	va_start(ap, input);
	while (i-- >= 0)
	{
		l = ft_next_arg(ap, &str);
		if (l == 1)
			k++;
		else if (l == -1)
			return (0);
	}
	va_end(ap);
	j = ft_strlen(ft_strinsert("", "", 2)) + k;
	if ((j - k) == 0)
		ft_putchar(0);
	else
		ft_putstr(ft_strinsert("", "", 2));
	ft_strinsert("", "", 4);
	return (j);
}
