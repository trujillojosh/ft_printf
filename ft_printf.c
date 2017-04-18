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

#include "ft_printf.h"

int 	main(int argc, char **argv)
{
	int 	c = -112698918;
	unsigned int d = (unsigned int)c;
	int a = -62;

	int *b = &a;
	ft_printf("This is a test %d", a);
	// ft_printf("%o Hello, percent %% %s, %cesting %d%i\n%p", c, "World", 't', ft_atoi("-9"), ft_atoi("0"), b);
	return (0);
}

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	char 		*str;

	i = ft_char_count((char *)input, '%');
	if (i == 0)
		i++;
	str = ft_strdup(input);
	va_start(ap, input);
	while (i > 0)
	{
		if (ft_next_arg(ap, &str, i) >= 0)
			i--;
		else
			break ;
	}
	ft_putstr(ft_strinsert("", "", 2));
	va_end(ap);
	return (0);
}
