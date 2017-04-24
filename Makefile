# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 22:45:57 by jtrujill          #+#    #+#              #
#    Updated: 2017/04/12 22:46:00 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
INC = -I ft_printf.h
FLAGS = gcc
#-Wall -Wextra -Werror#

SRCS = ft_printf.c conversions/ft_up_c.c conversions/ft_up_d.c conversions/ft_up_o.c \
	   conversions/ft_up_s.c conversions/ft_up_u.c conversions/ft_up_x.c conversions/ft_c.c \
	   conversions/ft_d.c conversions/ft_o.c conversions/ft_p.c \
	   conversions/ft_s.c conversions/ft_u.c conversions/ft_x.c flags/ft_plus.c \
	   flags/ft_minus.c flags/ft_0.c flags/ft_h.c flags/ft_hashtag.c flags/ft_hh.c \
	   flags/ft_j.c flags/ft_l.c flags/ft_ll.c flags/ft_space.c flags/ft_z.c conversions/ft_percent.c \
	   ft_next_arg.c ft_strinsert.c ft_is_over.c flags/ft_width.c

all: $(NAME)

$(NAME):
	@make all -C libft
	@$(FLAGS) $(INC) -o $(NAME) $(SRCS) -L libft/ -lft -g

clean:
	@make clean -C libft
	@rm -rf

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf ft_printf.dSYM

re: fclean all
