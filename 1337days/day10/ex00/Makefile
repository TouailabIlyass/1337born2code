# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itouaila <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 18:56:12 by itouaila          #+#    #+#              #
#    Updated: 2018/08/10 00:52:42 by itouaila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUTPUT = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS_PATH = ./srcs

INCLUDES_PATH = ./includes

SRCS = $(SRCS_PATH)/*.c

all:
	gcc -c $(SRCS) $(FLAGS) -I $(INCLUDES_PATH)
	ar cr $(OUTPUT) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

