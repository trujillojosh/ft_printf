/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:16 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/04 03:24:04 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "stdio.h"
#include <limits.h>

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
	// ft_printf("%hd", 32768);
	// printf("\n%hd", 32768);
	// int j = ft_printf("%zd", LLONG_MAX);
	// printf("\n");
	// int k = printf("%zd", LLONG_MAX);
	// printf("\nj is %d, k is %d", j, k);
	// ft_printf("%hd", 32768);
	// printf("\n");
	// printf("%hd", 32768);
	// int j = ft_printf("111%s333", "222");
	// printf("\n");
	// int k = printf("111%s333", "222");
	// printf("\nj is %d, k is %d", j, k);
	// ft_printf("%U", 4294967296);
	// printf("\n%U", 4294967296);
	// ft_printf("%lld", -9223372036854775808);
	// int j = ft_printf(" 1|%zd|1 ", LLONG_MAX);
	// j += ft_printf("\n 2|%zd|2 ", LLONG_MAX);
	// printf("\n");
	// int k = printf("%zd", LLONG_MAX);
	// printf("\nj is %d, k is %d", j, k);
	int i = ft_printf("%hhd", -129);
	printf("\n");
	int k = printf("%hhd", -129);
	printf("\ni is %d, k is %d", i, k);
}
