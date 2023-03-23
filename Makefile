
CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c utils.c \
		ft_split.c sort_100.c\
		instractions.c sorting.c\
		instractions_2.c instractions_3.c\
		parsing.c utils_2.c sort_utils.c\
		gnl/get_next_line_utils.c 
SRC_bonus = checker.c utils.c \
		ft_split.c sort_100.c\
		instractions.c sorting.c\
		instractions_2.c instractions_3.c\
		parsing.c utils_2.c sort_utils.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c 

OBJS = $(SRC:.c=.o)
OBJS_bonus = $(SRC_bonus:.c=.o)
all: push_swap

push_swap : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o push_swap

bonus : $(OBJS_bonus)
	$(CC) $(FLAGS) $(OBJS_bonus) -o checker

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_bonus)

fclean: clean
	$(RM) push_swap checker

re: fclean push_swap bonus