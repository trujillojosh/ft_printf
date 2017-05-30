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
	unsigned long e = 4294967296;
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
	// ft_printf("%i\n%p", ft_atoi("123"), b);
	// ft_printf("testing, %+012d", 98);
	// ft_printf( "%5d", 112);
	// ft_printf("hello");
	// ft_printf("%-5c", 'a');
	// int res = ft_printf("%.0%");
	// printf("\n\nres is --> %d", res);
	// ft_printf("%   %", "test");
	// ft_printf("%.0%");
	// ft_printf( "%.3d", 10 );
	// ft_printf("@moulitest: %#.x %#.0x", 0, 0); //wtf is this supposed to do
	// ft_printf("%+ d", 42);
	// ft_printf("%0+5d", 42);
	// ft_printf("%05d", 42);
	printf("%U", e);
}

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	char 		*str;
	char 		*tmp;

	i = ft_char_count((char *)input, '%');
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
		if (ft_next_arg(ap, &str, i) >= 0)
			i--;
		else
			break ;
	}
	if (tmp)
		ft_strdel(&tmp);
	ft_putstr(ft_strinsert("", "", 2));
	va_end(ap);
	return (ft_strlen(ft_strinsert("", "", 2)));
}
