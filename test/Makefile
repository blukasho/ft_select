# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 12:08:45 by blukasho          #+#    #+#              #
#*   Updated: 2019/07/05 11:20:34 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = test_tgetstr.c

FLAGS =  -g3 -fsanitize=address

all:
	gcc $(FLAGS) -Iincludes -I../libft/includes $(SRCS) ./libft.a -ltermcap
