# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalka <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:40:50 by gmalka            #+#    #+#              #
#    Updated: 2021/11/22 14:00:56 by gmalka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC			=	$(shell find . -name "*.c")

OBJ			=	$(SRC:.c=.o)

HEADER		=	fractal.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re bonus
	
all		:	$(NAME)

bonus	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all
