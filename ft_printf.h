#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

int		ft_printf(const char *input, ...);
int		ft_plus(char **s1);
int		ft_minus(char **s1);
int		ft_0(char **s1);
int		ft_h(char **s1);
int		ft_hashtag(char **s1);
int		ft_hh(char **s1);
int		ft_j(char **s1);
int		ft_l(char **s1);
int		ft_ll(char **s1);
int		ft_space(char **s1);
int		ft_z(char **s1);

int		ft_up_c(char **s1);
int		ft_up_d(char **s1);
int		ft_up_o(char **s1);
int		ft_up_s(char **s1);
int		ft_up_u(char **s1);
int		ft_up_x(char **s1);
int		ft_c(va_list ap, char **s1);
int		ft_d(va_list ap, char **s1);
int		ft_o(char **s1);
int		ft_p(char **s1);
int		ft_s(va_list ap, char **s1);
int		ft_u(char **s1);
int		ft_x(char **s1);
int 	ft_percent(char **s1);

int		ft_next_arg(va_list ap, char **str, int i);
static char	ft_find_type(char **str);
int 	main(int argc, char **argv);
char	*ft_strinsert(char *s1, char *s2);

#endif
