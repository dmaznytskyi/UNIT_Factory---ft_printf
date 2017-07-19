# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    comp.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 15:02:22 by dmaznyts          #+#    #+#              #
#    Updated: 2017/07/19 19:36:04 by dmaznyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

while :
do
	clear
	echo "\033[1mCompiling libftprintf (including libft functions)...\033[0m"
	make re
	echo "\033[1;32mDONE\033[0m"
	make clean
	echo "\033[1mCompiling executable...\033[0m"
	clang -g -Wall -Wextra -Werror -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal -I ./ -o printf_main2.o -c printf_main2.c
	clang -g -o ft_printf printf_main2.o -I ./ -L ./ -lftprintf
#	echo "WARNING: no flags"
#	clang -g -I ./ -o main.o -c main.c
#	clang -g -o ft_printf main.o -I ./ -L ./ -lftprintf
	/bin/rm -f main.o printf_main2.o
	echo "\033[1;32mDONE\033[0m"
	echo "\033[1mRunning ./ft_printf\n________________________________\033[0m
	\nOutput: \n[\033[1m"
	./ft_printf
	echo "\033[0m]\033[1;32m\nSCRIPT DONE\033[0m"
	sleep 10
done
