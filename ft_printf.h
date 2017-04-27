/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:32 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 22:46:34 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"
# include <stdio.h> //take this shit out before submitting

int		ft_printf(const char *input, ...)__attribute__((format(printf,1,2)));
int		ft_plus(char *str, char *todo, int start);
int		ft_minus(char *str, char *todo, int opt);
int		ft_0(char *str, char *todo, int opt);
int		ft_h(char **s1);
int		ft_hash(char *str, char *todo, int start);
int		ft_hh(char **s1);
int		ft_j(char **s1);
int		ft_l(char **s1);
int		ft_ll(char **s1);
int		ft_space(char *str, char *todo, int start);
int		ft_z(char **s1);

int		ft_up_x(va_list ap, char **s1);
int		ft_c(va_list ap, char **s1);
int		ft_d(va_list ap, char **s1);
int		ft_o(va_list ap, char **s1);
int		ft_p(va_list ap, char **s1);
int		ft_s(va_list ap, char **s1);
int		ft_u(va_list ap, char **s1);
int		ft_x(va_list ap, char **s1);
int 	ft_percent(char **s1);

int		ft_next_arg(va_list ap, char **str, int i);
static char	*ft_find_type(char *str);
int 	main(int argc, char **argv);
char	*ft_strinsert(char *s1, char *s2, int mode);
int 	ft_is_over(char c, int mode);
int 	ft_width(char *str, char *todo, int start);
char	*ft_remove_todo(char *todo, char *remove);

#endif
