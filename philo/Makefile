# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 13:55:31 by khovakim          #+#    #+#              #
#    Updated: 2022/08/19 14:25:05 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
SRCS	= $(wildcard ./*.c)
OBJS	= $(patsubst ./%.c, ./%.o, $(SRCS))
CFLAGS	= -Wall -Werror -Wextra -pthread -I.
CC		= gcc
RM		= rm -f

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all re clean fclean

