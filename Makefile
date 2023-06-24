# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 19:54:39 by abez-zir          #+#    #+#              #
#    Updated: 2023/06/24 01:47:07 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = main.c parsing.c put_in_list_a.c put_in_list_b.c push_swap.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c ft_memcpy.c

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