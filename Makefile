# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fenedina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:45:20 by fenedina          #+#    #+#              #
#   Updated: 2021/10/26 17:06:33 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME		= 		libftprintf.a
SOURCE		=		part_1.c part_2.c part_3.c
HEADER		=		ft_printf.h

OBJECTS		=		$(SOURCE:.c=.o)

CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
RM			=		rm -rf

all			:		$(NAME)

$(NAME)		:		$(OBJECTS)
					ar rcs $(NAME) $(OBJECTS)

%.o			:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean		:
					$(RM) $(OBJECTS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
