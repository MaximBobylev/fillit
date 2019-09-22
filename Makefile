# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbits <hbits@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 15:36:18 by kdune             #+#    #+#              #
#    Updated: 2019/09/21 23:14:38 by hbits            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = src/main.o src/input_val.o src/readmap_1.o src/readmap_2.o \
src/output_lst.o src/error.o src/validate.o
#SRC = $(patsubst %.o,%.c,$(OBJ))
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o : %.c
	@gcc $(FLAGS) -c -I./libft $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all