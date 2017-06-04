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
 	// ft_printf("%lld", 9223372036854775807);
 	// ft_printf("% u", 4294967295);
 	// ft_printf("%5.d %5.0d", 0, 0);
 	// ft_printf("%5%");
 	// int u = printf("|%2c|", 0);
 	// printf("\nu is %d", u);
 	// ft_printf("%s\n%8s\n%15s\n%s\n%5s\n%6s\n%10s\n", "Fuck", "This", "Project", "I", "need", "a", "beer");
 	// ft_printf("@moulitest: %#.o %#.0o", 0, 0);
 	// ft_printf("@moulitest: %#.x %#.0x", 0, 0);
 	// ft_printf("%03.2d", 0);
 	// ft_printf("%03.2d", -1);
 	// printf("%03.2d", 1);
 	// ft_printf("%010x", 542);
 	// int res = ft_printf("%.2c", NULL);

	// ft_printf("%U", "4294967296"); //this is total bs
	// int res = ft_printf("@moulitest: %s", NULL);
	// printf("\nres is %d", res);
	// ft_printf("%hd", 32768);
	ft_printf("%hhd", -128);
	// ft_printf("%lld", -9223372036854775808);
}

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
		j = ft_next_arg(ap, &str, i);
		if (j < 0)
			break ;
		else if (j == 1)
			k++;
		i--;
		// if (ft_next_arg(ap, &str, i) >= 0)
		// 	i--;
		// else
		// 	break ;
	}
	if (tmp)
		ft_strdel(&tmp);
	va_end(ap);
	ft_putstr(ft_strinsert("", "", 2));
	return (ft_strlen(ft_strinsert("", "", 2)) + k);
}
