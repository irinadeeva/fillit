# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amargy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 18:31:35 by amargy            #+#    #+#              #
#    Updated: 2019/08/22 21:09:18 by amargy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/main.c \
	   ./srcs/input_valid.c \
	   ./srcs/put_figure_in_structure.c \
	   ./srcs/map.c \
	   ./srcs/fillit.c \

OBJS = $(SRCS:.c=.o)

GCCFLAGS = -Wall -Wextra -Werror

all: $(NAME)
		@make -C ./libft
		@gcc $(GCCFLAGS) - o $(NAME) $(OBJS) \
			-L ./libft/ -I ./ -I ./libft

clean:
		@rm -f $(OBJS)
		@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft

re: fclean all
		
		
