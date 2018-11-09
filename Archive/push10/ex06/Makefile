# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itouaila <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 18:56:43 by itouaila          #+#    #+#              #
#    Updated: 2018/08/10 00:50:16 by itouaila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

COMPILER = gcc *.c -Wall -Wextra -Werror

all:
	$(COMPILER) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
