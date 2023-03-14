# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:16:21 by mmesbahi          #+#    #+#              #
#    Updated: 2023/03/14 13:30:02 by mmesbahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

RM = rm -rf

SRC = parcing.c utils.c \
		ft_split.c \
		ins.c sorting.c

OBJ = $(SRC:.c=.o)

all :$(NAME) 


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all bonus 

clean:
		$(RM) $(OBJ)
fclean : clean
		$(RM) $(NAME)