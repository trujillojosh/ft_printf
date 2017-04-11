#include "ft_printf.h"

int 	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Only enter one argument, dumbass.");
	}
	else
	{
		ft_printf(argv[1], "%s");
	}
	return (0);
}

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	char 		*str;

	i = ft_char_count((char *)input, '%') + 1;
	str = ft_strdup(input);
	va_start(ap, input);
	// tic = va_arg(ap, char *);
	// ft_putendl(tic);
	// tic = va_arg(ap, char *);
	// ft_putendl(tic);
	// ft_putstr(input);
	// va_end(ap);
	// ft_putnbr(i);
	// tic = va_arg(ap, ft_arg_type(input, i));
	while (i > 0)
	{
		if (ft_next_arg(ap, &str, i))
			i--;
		else
			return (-1);
	}
	// ft_putstr(va_arg);
	// while (i > 0)
	// {
	// 	// type = ft_strdup("char*");
	// 	tic = va_arg(ap, type);
	// }
	return (0);
}