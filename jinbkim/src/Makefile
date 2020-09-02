# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 18:11:27 by jinbkim           #+#    #+#              #
#    Updated: 2020/09/02 16:06:52 by jinbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= $(wildcard *.c)
OBJS	= $(SRC:.c=.o)

NAME	= minishell
RM		= rm -rf
LIB		= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all 	: $(NAME)

clean	:
		$(RM) $(OBJS) *.gch *.out

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)