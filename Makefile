# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maducham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/17 02:01:44 by maducham          #+#    #+#              #
#    Updated: 2014/11/17 04:17:20 by maducham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all

SRC = $(wildcard *.c)
O_FILE = $(SRC:.c=.o)
NAME = ft_ls
FLAGS =  -Wall -Werror -Wextra

$(NAME): $(O_FILE)
	gcc -g $(FLAGS) -o $@ $^

all:
	gcc -g $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -fr *.o

fclean: clean
	rm -fr $(NAME) *.o

re: fclean all

%.o: %.c
	gcc -c $^
