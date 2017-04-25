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
	int 	c = 112698918;
	unsigned int d = (unsigned int)c;
	int a = 120;

	int *b = &a;
	// printf("This is a test %o", a);
	// printf("%050d", a);
	// ft_printf("% -0d", 10);
	ft_printf("%o Hello, percent %% %s, %cesting %10d%i\n%p", c, "World", 't', ft_atoi("-9"), ft_atoi("0"), b);
	// printf("%+012d", 12);
	// printf("%i\n%p", ft_atoi("123"), b);
	// printf("testing, %+012d", 98);
	return (0);
}

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	char 		*str;
	char 		*tmp;

	i = ft_char_count((char *)input, '%') - 1;
	if (i == 0)
		i++;
	str = ft_strdup(input);
	tmp = str;
	va_start(ap, input);
	while (i > 0)
	{
		if (ft_next_arg(ap, &str, i) >= 0)
			i--;
		else
			break ;
	}
	ft_strdel(&tmp);
	tmp = ft_strinsert("", "", 2);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	va_end(ap);
	return (0);
}
