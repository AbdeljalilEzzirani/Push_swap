# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 19:54:39 by abez-zir          #+#    #+#              #
#    Updated: 2023/07/15 16:21:31 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror 

NAME = push_swap
BONUS = checker

SRC = src/main.c src/parsing.c src/put_in_list_a.c src/put_in_list_b.c src/push_swap.c src/ft_split.c \
		src/ft_union.c src/ft_putstr_fd.c src/ft_atoi.c src/ft_list.c src/ft_util.c
		
SRC_BONUS = bonus/main.c bonus/ft_bonus.c bonus/parsing.c bonus/put_in_list_a.c bonus/put_in_list_b.c bonus/push_swap.c \
		bonus/ft_split.c bonus/ft_strncmp.c bonus/ft_union.c bonus/ft_putstr_fd.c bonus/ft_atoi.c bonus/ft_list.c \
		bonus/ft_util.c bonus/get_next_line.c bonus/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ_BONUS)
		$(CC) $(FLAGS) $(OBJ_BONUS) -o $(BONUS)

%.o: src/%.c push_swap.h
		$(CC) $(FLAGS) -c $< -o $@

%.o: bonus/%.c ./checker.h
		$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
		rm -rf $(OBJ)
		rm -rf $(OBJ_BONUS)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(BONUS)

re: fclean all
