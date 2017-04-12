#include "../ft_printf.h"

int		ft_percent(char **s1) /* No argument expected */ 
{
	char 	s2[2];

	s2[0] = '%';
	s2[1] = '\0';
	*s1 = ft_strinsert(*s1, s2, 1);
	return (0);
}
