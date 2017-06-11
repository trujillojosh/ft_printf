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

// char	*ft_itoa_dispatch(void *nb, char *todo, int base)
// {
// 	char	c;

// 	c = todo[ft_strlen(todo) - 1];
// 	if (c == 'D')
// 		return (ft_itoa_ll((long long)nb));
// 	c = ft_tolower(c);
// 	if (ft_char_count(todo, 'j') > 0)
// 	{
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_m((intmax_t)nb));
// 		return (ft_umitoa_base((uintmax_t)nb, base));
// 	}
// 	else if (ft_char_count(todo, 'z') > 0)
// 		return (ft_titoa_base((size_t)nb, base));
// 	if ((ft_char_count(todo, 'h') > 0) || (ft_char_count(todo, 'l') > 0))
// 		return (ft_itoa_helper(nb, todo, base, c));
// 	if ((c == 'i') || (c == 'd'))
// 		return (ft_itoa((int)nb));
// 	return (ft_uitoa_base((unsigned int)nb, base));
// }

static int 	cast_find(char *todo, char c)
{
	if (c == 'D')
		return (8);
	else if (c == 'U')
		return (9);
	c = ft_tolower(c);
	if (ft_char_count(todo, 'j') > 0)
	{
		if ((c == 'd') || (c == 'i'))
			return (10);
		return (11);
	}
	else if (ft_char_count(todo, 'z') > 0)
		return (12);
	else if (ft_char_count(todo, 'h') > 0)
	{
		if (ft_char_count(todo, 'h') > 1)
		{
			if ((c == 'd') || (c == 'i'))
				return (2);
			return (3);
		}
		if ((c == 'd') || (c == 'i'))
			return (4);
		return (5);
	}
	else if (ft_char_count(todo, 'l') > 0)
	{
		if (ft_char_count(todo, 'l') > 1)
		{
			if ((c == 'd') || (c == 'i'))
				return (8);
			return (9);
		}
		if ((c == 'd') || (c == 'i'))
			return (6);
		return (7);
	}
	if ((c == 'd') || (c == 'i'))
		return (0);
	return (1);
}
// static char 	*ft_itoa_helper(void *nb, char *todo, int base, char c)
// {
// 	if (ft_char_count(todo, 'h') > 0)
// 	{
// 		if (ft_char_count(todo, 'h') > 1)
// 		{
// 			if ((c == 'd') || (c == 'i'))
// 				return (ft_itoa_m((char)nb));
// 			return (ft_umitoa_base(((unsigned char)nb), base));
// 		}
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_m((short)nb));
// 		return (ft_umitoa_base((unsigned short)nb, base));
// 	}
// 	else
// 	{
// 		if (ft_char_count(todo, 'l') > 1)
// 		{
// 			if ((c == 'd') || (c == 'i'))
// 				return (ft_itoa_m((long long)nb));
// 			return (ft_umitoa_base((unsigned long long)nb, base));
// 		}
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_m((long)nb));
// 		return (ft_umitoa_base((unsigned long)nb, base));
// 	}
// }
char 	*ft_itoa_dispatch(void *nb, char *todo, int base)
{
	char 	c;
	int 	i;
	char 	*res;
	char 	*tmp;
	int 	neg;

	c = todo[ft_strlen(todo) - 1];
	i = cast_find(todo, c);
	neg = 0;
	if ((intmax_t)nb < 0)
		neg = 1;
	if (i == 0)
		res = ft_itoa_m((int)nb);
	else if (i == 1)
		res = ft_umitoa_base((unsigned int)nb, base);
	else if (i == 2)
		res = ft_itoa_m((char)nb);
	else if (i == 3)
		res = ft_umitoa_base((unsigned char)nb, base);
	else if (i == 4)
		res = ft_itoa_m((short)nb);
	else if (i == 5)
		res = ft_umitoa_base((unsigned short)nb, base);
	else if (i == 6)
		res = ft_itoa_m((long)nb);
	else if (i == 7)
		res = ft_umitoa_base((unsigned long)nb, base);
	else if (i == 8)
		res = ft_umitoa_base((long long)nb, base);
	else if (i == 9)
		res = ft_umitoa_base((unsigned long long)nb, base);
	else if (i == 10)
		res = ft_umitoa_base((intmax_t)nb, base);
	else if (i == 11)
		res = ft_umitoa_base((uintmax_t)nb, base);
	else
		res = ft_umitoa_base((size_t)nb, base);
	if ((neg == 1) && (base == 10) && (res[0] != '-'))
	{
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 9) || (i == 11))
			return (res);
		tmp = ft_strjoin("-", res);
		ft_strdel(&res);
		return (tmp);
	}
	return (res);


}
// char	*ft_itoa_dispatch(void *nb, char *todo, int base)
// {
// 	char	c;

// 	c = todo[ft_strlen(todo) - 1];
// 	// if ((intmax_t)nb < 0)
// 	// {
// 	// 	char *tmp = ft_strdup("-");
// 	// 	char *tmp2 = ft_umitoa_base((uintmax_t)nb, base);
// 	// 	return (ft_strjoin(tmp, tmp2));
// 	// }
// 	if (c == 'D')
// 		return (ft_itoa_m((long long)nb));
// 	c = ft_tolower(c);
// 	if (ft_char_count(todo, 'j') > 0)
// 	{
// 		if ((c == 'd') || (c == 'i'))
// 			return (ft_itoa_m((intmax_t)nb));
// 		return (ft_umitoa_base((uintmax_t)nb, base));
// 	}
// 	else if (ft_char_count(todo, 'z') > 0)
// 		return (ft_umitoa_base((size_t)nb, base));
// 	if ((ft_char_count(todo, 'h') > 0) || (ft_char_count(todo, 'l') > 0))
// 		return (ft_itoa_helper(nb, todo, base, c));
// 	if ((c == 'i') || (c == 'd'))
// 		return (ft_itoa_m((int)nb));
// 	return (ft_umitoa_base((unsigned int)nb, base));
// }