#include "ft_printf.h"

// int 	main(int argc, char **argv)
// {
// 	if (argc != 3)
// 	{
// 		ft_putstr("Only enter two arguments, dumbass.");
// 	}
// 	else
// 	{
// 		ft_printf(argv[1], argv[2]);
// 	}
// 	return (0);
// }

int		ft_printf(const char *input, ...)
{
	va_list 	ap;
	int 		i;
	char 		*str;

	i = ft_char_count((char *)input, '%');
	if (i == 0)
		i++;
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
			break ;
	}
	// ft_putstr(va_arg);
	// while (i > 0)
	// {
	// 	// type = ft_strdup("char*");
	// 	tic = va_arg(ap, type);
	// }
	ft_putstr(str);
	return (0);
}