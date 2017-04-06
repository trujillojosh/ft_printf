#include "ft_printf.h"

int		ft_printf(const char *input, ...)
{
	return (0);
}

int 	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Only enter one argument, dumbass.");
	}
	ft_printf(argv[1]);
	return (0);
}