# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 15:08:41 by jcorwin           #+#    #+#              #
#    Updated: 2018/12/23 22:53:45 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c list.c tetr.c map.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cd libft/ && make
	gcc -c $(FLAG) $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	cd libft/ && make clean
	rm -f $(OBJ)

fclean:	clean
	cd libft/ && make fclean
	rm -f $(NAME)

re: fclean all
