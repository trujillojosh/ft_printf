/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:24:02 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/01 23:41:53 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static char 	*ft_itoa_helper(void *nb, char *todo, int base, char c)
// {
// 	if (ft_char_count(todo, 'h') > 0)
// 	{
// 		if (ft_char_count(todo, 'h') > 1)
// 		{
// 			if ((c == 'd') || (c == 'i'))
// 				return (ft_itoa((int)nb));
// 			return (ft_uitoa_base(((unsigned int)nb), base));
// 		}
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_s((short)nb));
// 		return (ft_usitoa_base((unsigned short)nb, base));
// 	}
// 	else
// 	{
// 		if (ft_char_count(todo, 'l') > 1)
// 		{
// 			if ((c == 'd') || (c == 'i'))
// 				return (ft_itoa_ll((long long)nb));
// 			return (ft_ullitoa_base((unsigned long long)nb, base));
// 		}
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_l((long)nb));
// 		return (ft_ulitoa_base((unsigned long)nb, base));
// 	}
// }
char	*ft_itoa_dispatch(void *nb, char *todo, int base)
{
	char	c;

	c = ft_tolower(todo[ft_strlen(todo) - 1]);
	if ((c == 'd') || (c == 'i'))
		return (ft_itoa_ll((long long)nb));
	else
		return (ft_ullitoa_base((unsigned long long)nb, base));
	// if (ft_char_count(todo, 'j') > 0)
	// {
	// 	if ((c == 'd') || (c == 'i'))
	// 		return (ft_itoa_m((intmax_t)nb));
	// 	return (ft_umitoa_base((uintmax_t)nb, base));
	// }
	// else if (ft_char_count(todo, 'z') > 0)
	// 	return (ft_titoa_base((size_t)nb, base));
	// if ((ft_char_count(todo, 'h') > 0) || (ft_char_count(todo, 'l') > 0))
	// 	return (ft_itoa_helper(nb, todo, base, c));
	// if ((c == 'i') || (c == 'd'))
	// 	return (ft_itoa((int)nb));
	// return (ft_uitoa_base((unsigned int)nb, base));
}
