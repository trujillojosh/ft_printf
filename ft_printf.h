#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

int		ft_printf(const char *input, ...);
int		ft_+(char **str);
int		ft_-(char **str);
int		ft_0(char **str);
int		ft_h(char **str);
int		ft_hashtag(char **str);
int		ft_hh(char **str);
int		ft_j(char **str);
int		ft_l(char **str);
int		ft_ll(char **str);
int		ft_space(char **str);
int		ft_z(char **str);

int		ft_up_c(char **str);
int		ft_up_d(char **str);
int		ft_up_o(char **str);
int		ft_up_s(char **str);
int		ft_up_u(char **str);
int		ft_up_x(char **str);
int		ft_c(char **str);
int		ft_d(char **str);
int		ft_i(char **str);
int		ft_o(char **str);
int		ft_p(char **str);
int		ft_s(char **str);
int		ft_u(char **str);
int		ft_x(char **str);

#endif
