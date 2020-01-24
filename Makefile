#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/28 17:41:01 by blukasho          #+#    #+#             *#
#*   Updated: 2019/07/11 17:46:23 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = main.c init.c clear.c error.c read.c out.c keys.c window.c count.c\
	   cursor.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

CURR_PATH = .

LIB_NAME = libft/libft.a


FT_SELECT = ft_select

FLAGS = -Wall -Wextra -Werror -Iincludes

DEBUG_FLAGS = -g3 -fsanitize=address

FT_SELECT_MAIN = srcs/main.c

all: make_objs_dir make_lib $(FT_SELECT)

$(FT_SELECT): $(LIB_NAME) $(FT_SELECT_MAIN)
	gcc $(FLAGS) $(FT_SELECT_MAIN) $(LIB_NAME) -o $(FT_SELECT) -ltermcap

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

set_debug_flags:
	$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

debug: make_debug_lib set_debug_flags all

make_debug_lib:
	make debug -C $(LIBFT_PATH)

make_objs_dir:
	@mkdir -p $(OBJ_DIR)

make_lib:
	@make -C $(LIBFT_PATH)

make_clean_lib:
	make clean -C $(LIBFT_PATH)

clean: make_clean_lib
	rm -rf $(OBJ_DIR) 

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rvf ft_select.dSYM
	rm -rvf $(FT_SELECT)

re: fclean all

.PHONY: all clean fclean re debug
