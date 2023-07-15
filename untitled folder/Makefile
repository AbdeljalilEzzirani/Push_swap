# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 19:54:39 by abez-zir          #+#    #+#              #
#    Updated: 2023/07/15 00:05:27 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror 

NAME = push_swap
BONUS = checker

SRC = main.c parsing.c put_in_list_a.c put_in_list_b.c push_swap.c ft_split.c \
		ft_union.c ft_putstr_fd.c ft_atoi.c ft_list.c ft_util.c
		
SRC_BONUS = checker/main.c checker/parsing.c checker/put_in_list_a.c checker/put_in_list_b.c checker/push_swap.c \
		checker/ft_split.c checker/ft_strncmp.c checker/ft_union.c checker/ft_putstr_fd.c checker/ft_atoi.c checker/ft_list.c \
		checker/ft_util.c checker/get_next_line.c checker/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ_BONUS)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(FLAGS) -c $< -o $@

%.o: checker/%.c checker/checker.h
		$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(BONUS)

re: fclean all
