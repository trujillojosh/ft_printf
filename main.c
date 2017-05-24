/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:16 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/11 16:00:19 by jtrujill         ###   ########.fr       */
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
	ft_printf("%i\n%p", ft_atoi("123"), b);
	// printf("testing, %+012d", 98);
	// ft_printf( "%5d", 112);
}