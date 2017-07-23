# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 13:18:17 by dmaznyts          #+#    #+#              #
#    Updated: 2017/07/23 21:20:45 by dmaznyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = ft_printf.o ft_putstr_until.o ft_cv.o ft_ns.o ft_pf.o ft_pfw.o\
	  ft_pprec.o ft_findallmodifiers.o ft_psm.o	ft_writeout.o\
	  ft_s_small.o ft_s_big.o ft_p_small.o ft_d_small.o ft_d_big.o\
	  ft_i_small.o ft_o_small.o ft_o_big.o ft_u_small.o ft_u_big.o\
	  ft_x_small.o ft_x_big.o ft_c_small.o ft_c_big.o\
	  ft_itoa_base.o ft_isflag.o ft_is_sm.o\
	  printf_info.o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -g -c -o $@ $<

$(NAME): $(OBJ) libft/libft.a
	ar -cru $(NAME) $(OBJ) 
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean
	
fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

libft/libft.a:
	make -C libft

re: fclean all
