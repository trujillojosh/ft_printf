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
	// ft_printf("%#12o Hello, percent %% %s, %cesting %++5d%+i\n%p", c, "World", 't', ft_atoi("-9"), ft_atoi("0"), b);
	// printf("%#-15X\n", 12);
	// ft_printf("%#-15X", 12);
	// ft_printf("%#19x", c);
	// ft_printf("%+10d", 12);
	// ft_putchar('\n');
	// ft_printf("%+10d", 12);
	// ft_putchar('\n');
	// printf("\n%+10d", 12);
	// ft_printf("%+12d", 12);
	// printf("%i\n%p", ft_atoi("123"), b);
	// printf("testing, %+012d", 98);
	printf( "%25.5d", 112);
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
	if (tmp)
		ft_strdel(&tmp);
	ft_putstr(ft_strinsert("", "", 2));
	ft_strinsert("", "", 4);
	va_end(ap);
	return (0);
}
