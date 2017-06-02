# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 22:45:57 by jtrujill          #+#    #+#              #
#    Updated: 2017/06/01 22:53:05 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_printf
INC = -I ft_printf.h
FLAGS = gcc
#-Wall -Wextra -Werror#

SRCS = ft_printf.c conversions/ft_up_x.c conversions/ft_c.c conversions/ft_d.c \
	   conversions/ft_o.c conversions/ft_p.c conversions/ft_s.c \
	   conversions/ft_u.c conversions/ft_x.c flags/ft_plus.c flags/ft_minus.c \
	   flags/ft_0.c flags/ft_hash.c \
	   flags/ft_space.c \
	   conversions/ft_percent.c ft_next_arg.c ft_strinsert.c ft_is_over.c \
	   flags/ft_width.c ft_remove_todo.c flags/ft_precision.c ft_itoa_dispatch.c

all: $(NAME)

$(NAME):
	@make all -C libft
	@$(FLAGS) $(INC) -o $(NAME) $(SRCS) -L libft/ -lft -g
	# @$(FLAGS) -c $(INC) $(SRCS)
	# ar rc $(NAME) *.o libft/libft.a
	# ranlib $(NAME)

clean:
	@make clean -C libft
	@rm -rf *.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf ft_printf.dSYM

re: fclean all
