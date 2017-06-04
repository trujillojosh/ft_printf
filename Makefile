# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 22:45:57 by jtrujill          #+#    #+#              #
#    Updated: 2017/06/04 01:12:52 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
INC = -I includes/ft_printf.h
FLAGS = gcc -c
#-Wall -Wextra -Werror#

SRCS = src/ft_is_over.c src/ft_itoa_dispatch.c src/ft_next_arg.c \
	   src/ft_printf.c src/ft_remove_todo.c src/ft_strinsert.c \
	   src/conversions/ft_c.c src/conversions/ft_d.c src/conversions/ft_o.c \
	   src/conversions/ft_p.c src/conversions/ft_percent.c \
	   src/conversions/ft_s.c src/conversions/ft_u.c src/conversions/ft_x.c \
	   src/conversions/ft_up_x.c src/flags/ft_0.c src/flags/ft_hash.c \
	   src/flags/ft_minus.c src/flags/ft_plus.c src/flags/ft_precision.c \
	   src/flags/ft_space.c src/flags/ft_width.c src/libft/ft_atoi.c \
	   src/libft/ft_bzero.c src/libft/ft_cd_freq.c src/libft/ft_char_count.c \
	   src/libft/ft_int_len.c src/libft/ft_int_len_ext.c \
	   src/libft/ft_isalnum.c src/libft/ft_isalpha.c src/libft/ft_isascii.c \
	   src/libft/ft_isdigit.c src/libft/ft_isprint.c src/libft/ft_itoa.c \
	   src/libft/ft_itoa_base.c src/libft/ft_itoa_l.c src/libft/ft_itoa_ll.c \
	   src/libft/ft_itoa_m.c src/libft/ft_itoa_s.c src/libft/ft_itoa_t.c \
	   src/libft/ft_itoa_u.c src/libft/ft_itoa_ul.c src/libft/ft_itoa_ull.c \
	   src/libft/ft_itoa_um.c src/libft/ft_itoa_us.c src/libft/ft_lstadd.c \
	   src/libft/ft_lstdel.c src/libft/ft_lstdelone.c src/libft/ft_lstiter.c \
	   src/libft/ft_lstmap.c src/libft/ft_lstnew.c src/libft/ft_lstsize.c \
	   src/libft/ft_memalloc.c src/libft/ft_memccpy.c src/libft/ft_memchr.c \
	   src/libft/ft_memcmp.c src/libft/ft_memcpy.c src/libft/ft_memdel.c \
	   src/libft/ft_memmove.c src/libft/ft_memset.c src/libft/ft_print_hex.c \
	   src/libft/ft_print_list.c src/libft/ft_putchar.c \
	   src/libft/ft_putchar_fd.c src/libft/ft_putendl.c \
	   src/libft/ft_putendl_fd.c src/libft/ft_putnbr.c \
	   src/libft/ft_putnbr_fd.c src/libft/ft_putstr.c src/libft/ft_putstr_fd.c \
	   src/libft/ft_str_replace.c src/libft/ft_strcat.c src/libft/ft_strchr.c \
	   src/libft/ft_strclr.c src/libft/ft_strcmp.c src/libft/ft_strcpy.c \
	   src/libft/ft_strdel.c src/libft/ft_strdup.c src/libft/ft_strequ.c \
	   src/libft/ft_striter.c src/libft/ft_striteri.c src/libft/ft_strjoin.c \
	   src/libft/ft_strlcat.c src/libft/ft_strlen.c src/libft/ft_strmap.c \
	   src/libft/ft_strmapi.c src/libft/ft_strncat.c src/libft/ft_strncmp.c \
	   src/libft/ft_strncpy.c src/libft/ft_strnequ.c src/libft/ft_strnew.c \
	   src/libft/ft_strnstr.c src/libft/ft_strrchr.c src/libft/ft_strrev.c \
	   src/libft/ft_strsplit.c src/libft/ft_strstr.c src/libft/ft_strsub.c \
	   src/libft/ft_strtrim.c src/libft/ft_titoa_base.c \
	   src/libft/ft_tolower.c src/libft/ft_toupper.c src/libft/ft_uitoa_base.c \
	   src/libft/ft_uint_len_ext.c src/libft/ft_ulitoa_base.c \
	   src/libft/ft_ullitoa_base.c src/libft/ft_umitoa_base.c \
	   src/libft/ft_until.c src/libft/ft_usitoa_base.c \
	   src/libft/ft_wspace_check.c src/libft/get_next_line.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(FLAGS) $(SRCS) $(INC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
