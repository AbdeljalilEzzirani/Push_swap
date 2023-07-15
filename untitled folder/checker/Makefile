# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 19:54:39 by abez-zir          #+#    #+#              #
#    Updated: 2023/07/15 00:08:13 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror 

NAME = checker

SRC = checker/main.c checker/parsing.c checker/put_in_list_a.c checker/put_in_list_b.c checker/push_swap.c \
		checker/ft_split.c checker/ft_strncmp.c checker/ft_union.c checker/ft_putstr_fd.c checker/ft_atoi.c checker/ft_list.c \
		checker/ft_util.c checker/get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
