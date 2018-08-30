# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 19:35:12 by cyfermie          #+#    #+#              #
#    Updated: 2017/11/29 19:39:04 by cyfermie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT_PATH = libft/

FLAGS = -Wall -Wextra -Werror

SRCS =  main.c \
		check_file_validity.c \
		check_one_tetri.c \
		create_and_init_t.c \
		get_file.c \
		resolve_fillit.c \
		resolve_fillit_2.c \
		shift.c \

OBJ = main.o \
		check_file_validity.o \
		check_one_tetri.o \
		create_and_init_t.o \
		get_file.o \
		resolve_fillit.o \
		resolve_fillit_2.o \
		shift.o \

LIBFT_LIB = -L $(LIBFT_PATH) -lft

all: $(NAME)

$(NAME): compile_libft
	gcc $(FLAGS) $(SRCS) -c
	gcc $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

compile_libft:
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
