/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:10 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 23:01:12 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_x(va_list ap, char **s1, int spec) /* Unsigned hexadecimal integer */ 
{
	void			*res;
	char 			*tmp;
	int 			i;

	i = 0;
	// if (spec == 1)
	// 	res = (unsigned int)va_arg(ap, unsigned short int);
	// else if (spec == 2)
	// 	res = (unsigned int)va_arg(ap, void *);
	// else if (spec == 3)
	// 	res = (unsigned int)va_arg(ap, unsigned long int);
	// else if (spec == 4)
	// 	res = (unsigned int)va_arg(ap, unsigned long long int);
	// else if (spec == 5)
	// 	res = (unsigned int)va_arg(ap, uintmax_t);
	// else if (spec == 6)
	// 	res = (unsigned int)va_arg(ap, size_t);
	// else
	res = va_arg(ap, void *);
	if ((res == 0) && (spec == 0))
		return (0);
	tmp = ft_uitoa_base((unsigned int)res, 16);
	while (tmp[i] != '\0')
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}

// void	*res;
// char	*stringthing;

// res = va_arg(ap, void *);
// if (spec == 1)
// {
// 	stringthing = itoa_base((int)*res);