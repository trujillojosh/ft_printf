#include "includes/libft.h"

int		ft_char_count(char *str, char c)
{
	int 	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
